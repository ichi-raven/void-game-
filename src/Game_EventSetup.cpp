#include "Game.hpp"
#include "CommonConstant.hpp"

enum BulletsName//ここでキーを登録
{
	eOP,
	eLine,
	eCircle,
};

void Game::BCSetup()//vector構築
{
	bc.emplace(eOP, std::vector<Bullet>());
	bc.emplace(eLine, std::vector<Bullet>());
	bc.emplace(eCircle, std::vector<Bullet>());

	for (auto &bVecPair : bc) //実行環境によって調整するといいかもしれない
		bVecPair.second.reserve(500);
}

void Game::eventSetup()
{
	constexpr auto lmdSpinVec2 = [](const Vec2 &v, const double &angle) -> Vec2 
	{
		return Vec2(v.x * cos(angle) - v.y * sin(angle),
					v.x * sin(angle) + v.y * cos(angle));
	};

	//本ステージでの弾幕における全体的な定数
	constexpr int OPNumOnce = 10;

	{
		constexpr double radius = 100;
		constexpr double speed = 10;

		auto &op = bc[eOP];

		auto lmdStart = [&](Event *pE) 
		{
			for (int i = 0; i < OPNumOnce; ++i)
			{
				op.emplace_back();
				op.back().setTexture(Texture(U"resources/Assets/Bullet_CircleW.png"));
				op.back().setScale(Vec2(1.7, 1.7));
				const double angle = 2 * M_PI / OPNumOnce * i;
				op.back().setPos(enemy.getPos() + Vec2(cos(angle), sin(angle)) * 100);
				op.back().setVel(Vec2(cos(angle - M_PI / 60), sin(angle- M_PI / 60)) * speed);
				op.back().setAcc(Vec2(-cos(angle - M_PI / 60), -sin(angle - M_PI / 60)) * speed * 0.05);
			}
		};

		auto lmdUpdate = [&](Event *pE) 
		{
			
			for (int i = 0; i < op.size(); ++i)
			{
				op[i].setVel(lmdSpinVec2(op[i].getVel(), M_PI / 360));

				const double angle = 2 * M_PI / OPNumOnce * i;

				//if(op[i].getPos().distanceFrom(enemy.getPos()) <= radius)
				if(op[i].getVel().length() >= speed)
					op[i].setVel(Vec2(cos(angle), sin(angle)) * speed);

				op[i].update();
			}
		};

		auto lmdEnd = [&](Event *pE) 
		{
			op.clear();
		};

		Event e(0, EventType::eOnce, lmdStart, lmdUpdate, lmdEnd);
		waitingEvents.push(e);
	}
	//------------------------------------------------------------------------
	{
		constexpr double speed = 6;

		auto &line = bc[eLine];
		auto &op = bc[eOP];

		auto lmdStart = [&](Event *pE) 
		{
			for (size_t i = 0; i < op.size(); ++i)
			{
				line.emplace_back();
				line.back().setTexture(Texture(U"resources/Assets/Bullet_RectangleB.png"));
				//line.back().setScale(Vec2(1.7, 1.7));
				//const double angle = 2 * M_PI / OPNumOnce * i + M_PI / 2;
				line.back().setPos(op[i].getPos());
				//line.back().setVel(line.back().getPos() - enemy.getPos().normalize() * speed);
				//op.back.setAcc(op.back().getVel() * 0.02);
			}
		};

		auto lmdUpdate = [&](Event *pE)
		{
			if (pE->getElapsedFrame() % 3 == 0)
				for (int i = 0; i < OPNumOnce; ++i)
				{
					line.emplace_back();
					line.back().setTexture(Texture(U"resources/Assets/Bullet_RectangleB.png"));
					line.back().setPos(op[i].getPos());
					//line.back().setVel((myShip.getPos() - line.back().getPos()).normalize() * speed);
					line.back().setVel((line.back().getPos() - enemy.getPos()).normalize() * speed);
					//op.back.setAcc(op.back().getVel() * 0.02);
				}

			for (auto &l : line)
			{
				l.update();

				//Print << line.size() << U"\n";
			}

			auto lmdErase = [&](const Bullet &b) {
				const Vec2 &pos = b.getPos();
				return pos.x < -100 ||
					   pos.x > windowSize.x + 100 ||
					   pos.y < -200 ||
					   pos.y > windowSize.y + 100;
			};
			{
				auto itr = std::remove_if(line.begin(), line.end(), lmdErase);
				line.erase(itr, line.end());
			}
		};

		auto lmdEnd = [&](Event *pE) {
			line.clear();
		};

		Event e(1, EventType::eOnce, lmdStart, lmdUpdate, lmdEnd);
		waitingEvents.push(e);
	}

	//------------------------------------------------------------------------
	{
		constexpr int shotNumOnce = 6;
		constexpr double speed = 5;

		auto &circle = bc[eCircle];
		auto &op = bc[eOP];

		auto lmdStart = [&](Event *pE) {

		};

		auto lmdUpdate = [&](Event *pE) {
			if (pE->getElapsedFrame() % 20000000 == 0)
				for (int i = 0; i < OPNumOnce; ++i)
					for (int j = 0; j < shotNumOnce; ++j)
					{
						circle.emplace_back();
						circle.back().setTexture(Texture(U"resources/Assets/Bullet_RectangleB.png"));
						const double angle = 2 * M_PI / shotNumOnce * j;
						circle.back().setPos(op[i].getPos());
						circle.back().setVel(Vec2(cos(angle), sin(angle)) * speed);
						//circle.back().setAcc(lmdSpinVec2(circle.back().getVel() * 0.01, M_PI / 360));
					}

			for (auto &c : circle)
			{
				//c.setVel(lmdSpinVec2(c.getVel(), M_PI / 360));
				c.update();
			}

			auto lmdErase = [&](const Bullet &b) {
				const Vec2 &pos = b.getPos();
				return pos.x < -100 ||
					   pos.x > windowSize.x + 100 ||
					   pos.y < -200 ||
					   pos.y > windowSize.y + 100;
			};
			circle.erase(std::remove_if(circle.begin(), circle.end(), lmdErase), circle.end());

			//if(circle.size() == 0)
			//pE->setEndFlag();
		};

		auto lmdEnd = [&](Event *pE) {
			circle.clear();
		};

		Event e(1, EventType::eOnce, lmdStart, lmdUpdate, lmdEnd);
		waitingEvents.push(e);
	}
}

