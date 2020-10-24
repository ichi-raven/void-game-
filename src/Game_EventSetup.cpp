// #include "Game.hpp"
// #include "CommonConstant.hpp"

// #include "SampleEB.hpp"

// void Game::BCSetup()
// {
// 	bc.emplace(eOP, std::vector<Bullet>());
// }



	// {
	// 	constexpr int per = 4;

	// 	auto &line = bc[eB1];
	// 	auto &line2 = bc[eB2];

	// 	auto lmdStart = [&](Event *pE) {
	// 		line.reserve(500);
	// 		line2.reserve(500);
	// 	};

	// 	auto lmdUpdate = [&](Event *pE) {
	// 		const auto f = pE->getElapsedFrame();
	// 		if (!(f % per))
	// 			for (int i = 0; i < bc[eOP].size(); ++i)
	// 			{
	// 				line.emplace_back();
	// 				auto &b = line.back();
	// 				const auto &op = bc[eOP][i];
	// 				b.setPos(op.getPos());
	// 				//b.setVel(lmdSpinVec2((enemy.getPos() - op.getPos()) * 0.02, M_PI / 180 * f));
	// 				b.setAcc(lmdSpinVec2((enemy.getPos() - op.getPos()).normalize() * 2, M_PI / 180 * f) * 0.012);

	// 				line2.emplace_back();
	// 				auto &b2 = line2.back();
	// 				b2.setTexture(Texture(U"resources/Assets/Bullet_RectangleW.png"));
	// 				b2.setPos(op.getPos());
	// 				b2.setVel((enemy.getPos() - op.getPos()).normalize() * 3);
	// 			}

	// 		for (auto &b : line)
	// 		{
	// 			//b.setVel(lmdSpinVec2(b.getVel(), -M_PI / 720));
	// 			//b.setAcc(b.getVel() * -0.0025);
	// 			b.update();
	// 		}

	// 		for (auto &b : line2)
	// 		{
	// 			//b.setVel(lmdSpinVec2(b.getVel(), -M_PI / 720));
	// 			//b.setAcc(b.getVel() * -0.0025);
	// 			b.update();
	// 		}

	// 		auto lmdErase = [&](const Bullet &b) {
	// 			const Vec2 &pos = b.getPos();
	// 			return pos.x < -100 ||
	// 				   pos.x > windowSize.x + 100 ||
	// 				   pos.y < -200 ||
	// 				   pos.y > windowSize.y + 100;
	// 		};

	// 		{
	// 			auto itr = std::remove_if(line.begin(), line.end(), lmdErase);
	// 			line.erase(itr, line.end());
	// 			auto itr2 = std::remove_if(line2.begin(), line2.end(), lmdErase);
	// 			line2.erase(itr2, line2.end());
	// 		}
	// 	};

	// 	auto lmdEnd = [&](Event *pE) 
	// 	{
	// 		line.clear();
	// 		line2.clear();
	// 	};

	// 	Event e(1.5, EventType::eOnce, lmdStart, lmdUpdate, lmdEnd);
	// 	waitingEvents.push(e);
	// }
//}