#include "Game.hpp"
#include "CommonConstant.hpp"

#include "SampleEB.hpp"

#include <cassert>

void Game::init()
{
	Profiler::EnableAssetCreationWarning(false);
	enemy.setPos(Vec2(windowSize.x / 2, windowSize.y / 3));
	myShip.setPos(Vec2(windowSize.x / 2, windowSize.y / 5 * 4));
	if(!music.play())
		Print << U"Error\n";
	music.setVolume(0.2); //------------------------

	assert(scoreLoader.load("resources/Score/score.dat"));

	notes = scoreLoader.getNotes();
	//BCSetup();
	eventSetup();

	mProgressBar.setPos(0, 0);


	//notes.clear();
}

void Game::eventSetup()
{
	for (const auto& n : notes)
	{
		waitingEvents.emplace_back();

		switch (n.first)
		{
		default:
			waitingEvents.back().setBehav(enemy, myShip, windowSize, std::make_shared<SampleEB>());
			waitingEvents.back().setTriggerTime(n.second);
			break;
		}
	}
}

void Game::update()
{

	checkInput();

	eventHandle();

	checkCollide();

	myShip.update();
	enemy.update();

	//Print << activeEvents.size();

	for (auto& ae : activeEvents)
		ae.update(enemy, myShip, music.posSec());

	mProgressBar.setSize((1 - music.posSec() / music.lengthSec()) * windowSize.x, 10);

	if(myShip.isDead())
	{
		getData().endWithDead = true;
		changeScene(U"Result");
	}
	
	if(!music.isPlaying())//終了
	{
		getData().endWithDead = false;
		changeScene(U"Result");
	}
}

void Game::draw() const
{
	mProgressBar.draw();
	myShip.draw(windowSize);
	enemy.draw();

	for(auto& ae : activeEvents)
		ae.draw();
}

void Game::checkInput()
{
	{
		const uint16_t speed = KeyShift.pressed() ? 3 : 7;
		Vec2 vel;
		Vec2 pos = myShip.getPos();

		if (!KeyUp.pressed() ^ KeyDown.pressed())
			vel.y = 0;
		else if (KeyUp.pressed())
			vel.y = pos.y >= 0 ? -speed : 0;
		else if (KeyDown.pressed())
			vel.y = pos.y <= windowSize.y ? speed : 0;

		if(!KeyLeft.pressed() ^ KeyRight.pressed())
			vel.x = 0;
		else if (KeyLeft.pressed())
			vel.x = pos.x >= 0 ? -speed : 0;
		else if (KeyRight.pressed())
			vel.x = pos.x <= windowSize.x ? speed : 0;

		myShip.setVel(vel);
	}
}

void Game::checkCollide()
{
	for(auto& ae : activeEvents)
		ae.checkHit(myShip);
}

void Game::eventHandle()
{
	while (
			!waitingEvents.empty() 
			&& 
			waitingEvents.back().getTriggerTime() - music.posSec() <= allowableErrorTime
		  )
	{
		Print << waitingEvents.back().getTriggerTime();
		activeEvents.emplace_back(std::move(waitingEvents.back()));
		waitingEvents.pop_back();
	}

	activeEvents.erase(
		std::remove_if(
			activeEvents.begin(), activeEvents.end(),
			[&](Event &e) 
			{
				return e.isEnded();
			}),
		activeEvents.end());
}
