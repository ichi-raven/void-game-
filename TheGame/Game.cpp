#include "Game.hpp"
#include "CommonConstant.hpp"

void Game::init()
{
	enemy.pos = Vec2(windowSize.x / 2, windowSize.y / 3);
	music.play();
	prevTime = 0;
	//適当に確保しておいた方がはやいとおもうよ
	bc.reserve(1000000);

	events.resize(2);
	Event e;
	e.eventTime = 3.1;
	e.eventName = "shoot";
	e.isExecuted = false;
	events.emplace_back(e);

	Profiler::EnableAssetCreationWarning(false);//大量の弾を生成するときにちゅういするやつ
}

void Game::update()
{
	input_update();
	myShip.update();
	enemy.update();
	BC_update();
	time_update();
	event_update();
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

		if(!KeyUp.pressed() ^ KeyDown.pressed())
			myShip.vel.y = 0;
		else if (KeyUp.pressed())
			myShip.vel.y = myShip.pos.y >= 0 ? -speed : 0;
		else if (KeyDown.pressed())
			myShip.vel.y = myShip.pos.y <= windowSize.y ? speed : 0;

		if(!KeyLeft.pressed() ^ KeyRight.pressed())
			myShip.vel.x = 0;
		else if (KeyLeft.pressed())
			myShip.vel.x = myShip.pos.x >= 0 ? -speed : 0;
		else if (KeyRight.pressed())
			myShip.vel.x = myShip.pos.x <= windowSize.x ? speed : 0;
	}

}


void Game::enemy_update()
{
	enemy.pos += enemy.vel += enemy.acc;
}

void Game::BC_update()
{
	constexpr int bulletNumOnce = 100;

	constexpr double speed = 10;

	static bool flg = true;
	constexpr double beat = 0.37267080;
	static double nextTime = beat;

	ClearPrint();

	const double gap = nextTime - time;

	//生成
	//if (!events.empty() && events.back().eventTime - time <= allowableErrorTime)
	if (nextTime - time <= allowableErrorTime && flg)
	{
		for (int i = 0; i < bulletNumOnce; ++i)
		{
			bc.emplace_back();
			bc.back().pos = enemy.pos;
			const double angle = 2 * M_PI / bulletNumOnce * i;

			bc.back().vel = Vec2(cos(angle), sin(angle)) * speed;
			//bc.back().acc = Vec2(cos(angle + M_PI / 360), sin(angle + M_PI / 360)) * 0.01;
		}

		//events.pop_back();
		flg = false;
		nextTime = time + gap + beat;

		Print << U"Generated";

	}
	else if (nextTime - time <= allowableErrorTime)
		flg = true;


	//更新
	for (auto& b : bc)
	{
		const double nextAngle = b.angle + M_PI / 72000;
		const Vec2 prevVel = b.vel;

		b.angle = atan(b.vel.y / b.vel.x);
		b.vel.x = prevVel.x * cos(nextAngle) - prevVel.y * sin(nextAngle);
		b.vel.y = prevVel.x * sin(nextAngle) + prevVel.y * cos(nextAngle);
		b.update();
	}

	//削除
	auto itr =  std::remove_if(bc.begin(), bc.end(),
		[&](const Bullet& b)
		{
			if (b.pos.x < 0 ||
				b.pos.x > windowSize.x ||
				b.pos.y < 0 ||
				b.pos.y > windowSize.y)
				return true;

			return false;
		});
	bc.erase(itr, bc.end());
}

void Game::event_update()
{
	
}