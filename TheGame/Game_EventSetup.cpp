#include "Game.hpp"
#include "CommonConstant.hpp"

enum BulletsName
{
	eB1,
	eB2,
};

void Game::BCSetup()
{
	
	bc.emplace(eB1, std::vector<Bullet>());
	bc.emplace(eB2, std::vector<Bullet>());

	//初期確保数は適当、
	for (auto& bVecPair : bc)
	{
		bVecPair.second.reserve(500);
	}
}

void Game::eventSetup()
{
	constexpr auto lmdSpinVec2 = [](const Vec2& v, const double& angle) -> Vec2
	{
		return Vec2(v.x * cos(angle) - v.y * sin(angle),
			v.x * sin(angle) + v.y * cos(angle));
	};

	{
		constexpr int bulletNumOnce = 30;
		constexpr int speed = 7;
		constexpr int speed2 = 7;

		auto lmdStart = [&](Event* pE)
		{
			for (int i = 0; i < bulletNumOnce; ++i)
			{
				const double angle = 2 * M_PI / bulletNumOnce * i;

				bc[eB1].emplace_back();
				bc[eB1].back().setPos(enemy.getPos());
				const Vec2 v1 = Vec2(cos(angle), sin(angle)) * speed;
				bc[eB1].back().setVel(v1);
				bc[eB1].back().setAcc(v1 * 0.01);
				//bc.back().acc = Vec2(cos(angle + M_PI / 360), sin(angle + M_PI / 360)) * 0.01;

				bc[eB2].emplace_back();
				bc[eB2].back().setPos(enemy.getPos());
				const Vec2 v2 = Vec2(cos(angle), sin(angle))* speed2;
				bc[eB2].back().setVel(v2);
				bc[eB2].back().setAcc(v2 * 0.01);
				bc[eB2].back().setTexture(U"Assets/Bullet_RectangleW.png");
			}
		};

		auto lmdUpdate = [&](Event* pE)
		{
			//更新
			for (auto& b : bc[eB1])
			{
				constexpr double spinAngle = M_PI / 150;
				const Vec2 v = lmdSpinVec2(b.getVel(), spinAngle);
				const Vec2 a = lmdSpinVec2(b.getAcc(), spinAngle) * 0.8;
				b.setVel(v);
				b.setAcc(a);
				b.update();
			}

			for (auto& b : bc[eB2])
			{
				constexpr double spinAngle = -M_PI / 150;
				const Vec2 v = lmdSpinVec2(b.getVel(), spinAngle);
				const Vec2 a = lmdSpinVec2(b.getAcc(), spinAngle) * 0.8;
				b.setVel(v);
				b.setAcc(a);
				b.update();
			}

			//削除
			auto lmdErase = [&](const Bullet& b)
			{
				const Vec2& pos = b.getPos();
				return	pos.x < -100 ||
					pos.x > windowSize.x + 100 ||
					pos.y < -200 ||
					pos.y > windowSize.y + 100;
			};

			{
				auto& bVec = bc[eB1];

				auto itr = std::remove_if(bVec.begin(), bVec.end(), lmdErase);
				bVec.erase(itr, bVec.end());

			}

			{
				auto& bVec = bc[eB2];

				auto itr = std::remove_if(bVec.begin(), bVec.end(), lmdErase);
				bVec.erase(itr, bVec.end());

			}
			
			if (bc[eB1].empty() && bc[eB2].empty())
				pE->setEndFlag(true);
		};

		auto lmdEnd = [&](Event* pE)
		{
			bc[eB1].clear();
			bc[eB2].clear();
		};

		Event e(5.0, EventType::eOnce, lmdStart, lmdUpdate, lmdEnd);
		waitingEvents.push(e);
	}
}