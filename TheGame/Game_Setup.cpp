#include "Game.hpp"
#include "CommonConstant.hpp"

enum BulletsName
{
	eB1,
	eB2,
};

void Game::BCSetup()
{
	//èâä˙âªå¬êîÇÕìKìñ
	bc.emplace(eB1, std::vector<Bullet>());
	bc.emplace(eB2, std::vector<Bullet>());

	for (auto& bVecPair : bc)
	{
		bVecPair.second.reserve(100);
	}
}

void Game::eventSetup()
{
	{
		constexpr int bulletNumOnce = 100;
		constexpr int speed = 6;
		constexpr int speed2 = 7;

		auto lmdStart = [&](Event* pE)
		{
			for (int i = 0; i < bulletNumOnce; ++i)
			{
				const double angle = 2 * M_PI / bulletNumOnce * i;

				bc[eB1].emplace_back();
				bc[eB1].back().setPos(enemy.getPos());

				bc[eB1].back().setVel(Vec2(cos(angle), sin(angle)) * speed);
				//bc.back().acc = Vec2(cos(angle + M_PI / 360), sin(angle + M_PI / 360)) * 0.01;

				bc[eB2].emplace_back();
				bc[eB2].back().setPos(enemy.getPos());

				bc[eB2].back().setVel(Vec2(cos(angle), sin(angle)) * speed2);
				bc[eB2].back().setTexture(U"Assets/Bullet_RectangleW.png");
			}
		};

		auto lmdUpdate = [&](Event* pE)
		{

			//çXêV
			for (auto& b : bc[eB1])
			{
				constexpr double spinAngle = M_PI / 180;
				const Vec2 prevVel = b.getVel();
				Vec2 v;
				v.x = prevVel.x * cos(spinAngle) - prevVel.y * sin(spinAngle);
				v.y = prevVel.x * sin(spinAngle) + prevVel.y * cos(spinAngle);
				b.setVel(v);
				b.update();
			}

			for (auto& b : bc[eB2])
			{
				b.update();
			}

			//çÌèú
			{
				auto& bVec = bc[eB1];

				auto itr = std::remove_if(bVec.begin(), bVec.end(),
					[&](const Bullet& b)
					{
						const Vec2& pos = b.getPos();
						return	pos.x < 0 ||
							pos.x > windowSize.x ||
							pos.y < 0 ||
							pos.y > windowSize.y;
					});
				bVec.erase(itr, bVec.end());

				if (bVec.empty())
					pE->setEndFlag(true);
			}

			{
				auto& bVec = bc[eB2];

				auto itr = std::remove_if(bVec.begin(), bVec.end(),
					[&](const Bullet& b)
					{
						const Vec2& pos = b.getPos();
						return	pos.x < 0 ||
							pos.x > windowSize.x ||
							pos.y < 0 ||
							pos.y > windowSize.y;
					});
				bVec.erase(itr, bVec.end());

			}
	
		};

		auto lmdEnd = [&](Event* pE)
		{
			bc[eB1].clear();
			bc[eB2].clear();
		};

		Event e;

		e.setTriggerTime(5.0);
		e.setStartFunc(lmdStart);
		e.setUpdateFunc(lmdUpdate);
		//e.setEndFunc(lmdEnd);
		waitingEvents.push(e);
	}
}