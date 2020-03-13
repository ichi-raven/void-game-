#include "Game.hpp"
#include "CommonConstant.hpp"

void Game::init()
{
	enemy.setPos(Vec2(windowSize.x / 2, windowSize.y / 3));
	music.play();
	//適当に確保しておいた方がはやいとおもうよ
	bc.reserve(10000);

	events.resize(2);
	Event e;
	e.eventTime = 3.1;
	e.eventName = "shoot";
	e.isExecuted = false;
	events.emplace_back(e);

	Profiler::EnableAssetCreationWarning(false);//大量の弾を生成するときにちゅういするやつ
	music.setVolume(0.1);
}

void Game::update()
{
	input_update();
	BC_update();
	time_update();
	event_update();

	myShip.update();
	enemy.update();
}

void Game::draw() const
{
	//Print << music.posSec();
	myShip.draw();
	enemy.draw();

	for (const auto& b : bc)
		b.draw();
}

void Game::time_update()
{
	time = music.posSec();
}

void Game::input_update()
{
	{
		constexpr int speed = 5;
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

void Game::BC_update()
{
	constexpr int bulletNumOnce = 100;

	constexpr double speed = 8;

	static bool flg = true;
	constexpr double beat = 0.37267080;
	static double nextTime = beat;

	const double gap = nextTime - time;

	//生成
	//if (!events.empty() && events.back().eventTime - time <= allowableErrorTime)
	if (nextTime - time <= allowableErrorTime && flg)
	{
		for (int i = 0; i < bulletNumOnce; ++i)
		{
			bc.emplace_back();
			bc.back().setPos(enemy.getPos());
			const double angle = 2 * M_PI / bulletNumOnce * i;

			bc.back().setVel(Vec2(cos(angle), sin(angle)) * speed);
			//bc.back().acc = Vec2(cos(angle + M_PI / 360), sin(angle + M_PI / 360)) * 0.01;
		}

		//events.pop_back();
		flg = false;
		nextTime = time + gap + beat;

	}
	else if (nextTime - time <= allowableErrorTime)
		flg = true;


	//更新
	for (auto& b : bc)
	{
		constexpr double spinAngle = M_PI / 720;
		const Vec2 prevVel = b.getVel();
		Vec2 v;
		v.x = prevVel.x * cos(spinAngle) - prevVel.y * sin(spinAngle);
		v.y = prevVel.x * sin(spinAngle) + prevVel.y * cos(spinAngle);
		b.setVel(v);
		b.update();
	}

	//削除
	auto itr =  std::remove_if(bc.begin(), bc.end(),
		[&](const Bullet& b)
		{
			Vec2 pos = b.getPos();
			if (pos.x < 0 ||
				pos.x > windowSize.x ||
				pos.y < 0 ||
				pos.y > windowSize.y)
				return true;

			return false;
		});
	bc.erase(itr, bc.end());
}

void Game::event_update()
{
	
}