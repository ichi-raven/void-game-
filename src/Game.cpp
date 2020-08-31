#include "Game.hpp"
#include "CommonConstant.hpp"

#include <cassert>

void Game::init()
{
	Profiler::EnableAssetCreationWarning(false);
	enemy.setPos(Vec2(windowSize.x / 2, windowSize.y / 3));
	myShip.setPos(Vec2(windowSize.x / 2, windowSize.y / 5 * 4));
	music.play();
	music.setVolume(0.2); //------------------------

	assert(scoreLoader.load("resources/Score/score.dat"));

	notes = scoreLoader.getNotes();

	BCSetup();
	eventSetup();
}

void Game::update()
{
	checkInput();

	eventHandle();

	checkCollide();

	myShip.update();
	enemy.update();

	for(auto& bVecPair : bc)
		for(auto& b : bVecPair.second)
		{
			b.update();
		}

	for (auto& ae : activeEvents)
		ae.executeUpdateFunc();
}

void Game::draw() const
{
	myShip.draw();
	enemy.draw();

	for (const auto& bVecPair : bc)
		for (const auto& b : bVecPair.second)
			b.draw();
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


void Game::eventHandle()
{
	while (
			!notes.empty() 
			&& 
			notes.back().second - music.posSec() <= allowableErrorTime
		  )
	{
		Print << notes.back().second;
		activeEvents.push_back(waitingEvents.front());
		notes.pop_back();
		activeEvents.back().executeStartFunc();
	}

	auto itr = std::remove_if(activeEvents.begin(), activeEvents.end(),
		[&](Event& e)
		{
			if (e.getEndFlag())
			{
				e.executeEndFunc();
				return true;
			}
			return false;
		});

	activeEvents.erase(itr, activeEvents.end());
}

void Game::checkCollide()
{
	for(const auto& bVecPair : bc)
		for(const auto& b : bVecPair.second)
		{
			//範囲制限による高速化、再考の余地あり
				if(b.getPos().x < myShip.getPos().x - 100||
					b.getPos().x > myShip.getPos().x + 100||
					b.getPos().y < myShip.getPos().y - 100||
					b.getPos().y > myShip.getPos().y + 100)
					continue;
			
			//衝突時のことを考えてない
			if(myShip.getPos().distanceFrom(b.getPos()) <= 10)
			{
				Print << U"Hit";
			}
		}
	
}