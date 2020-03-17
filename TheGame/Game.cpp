#include "Game.hpp"
#include "CommonConstant.hpp"

void Game::init()
{
	BCSetup();
	eventSetup();

	Profiler::EnableAssetCreationWarning(false);//大量の弾を生成するときにちゅういするやつ
	enemy.setPos(Vec2(windowSize.x / 2, windowSize.y / 3));
	music.play();
	music.setVolume(0.1);
}

void Game::update()
{
	input();

	eventHandle();

	myShip.update();
	enemy.update();

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


void Game::input()
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
	//今トリガーすべきイベントを移す
	while (
			!waitingEvents.empty() 
			&& 
			music.posSec() - waitingEvents.back().getTriggerTime() <= allowableErrorTime
		  )
	{
		activeEvents.emplace_back(waitingEvents.back());
		activeEvents.back().executeStartFunc();//スタート時に一度だけ
		waitingEvents.pop();
	}

	//終了したイベントをさよならする
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