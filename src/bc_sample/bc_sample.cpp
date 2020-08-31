// #include "Game.hpp"
// #include "CommonConstant.hpp"

// enum BulletsName
// {
//     eB1,
//     eB2,
//     eOP,
// };

// void Game::BCSetup()
// {
//     bc.emplace(eB1, std::vector<Bullet>());
//     bc.emplace(eB2, std::vector<Bullet>());
//     bc.emplace(eOP, std::vector<Bullet>());
// }

// void Game::eventSetup()
// {
//     constexpr auto lmdSpinVec2 = [](const Vec2 &v, const double &angle) -> Vec2 {
//         return Vec2(v.x * cos(angle) - v.y * sin(angle),
//                     v.x * sin(angle) + v.y * cos(angle));
//     };

//     {
//         constexpr int OPNumOnce = 6;
//         constexpr double radius = 200;
//         constexpr double speed = 5;

//         auto &op = bc[eOP];

//         auto lmdStart = [&](Event *pE) {
//             for (int i = 0; i < OPNumOnce; ++i)
//             {
//                 op.emplace_back();
//                 op.back().setTexture(Texture(U"resources/Assets/Bullet_CircleW.png"));
//                 op.back().setScale(Vec2(1.7, 1.7));
//                 const double angle = 2 * M_PI / OPNumOnce * i;
//                 op.back().setPos(enemy.getPos() + Vec2(cos(angle), sin(angle)) * radius);
//                 op.back().setVel(lmdSpinVec2(Vec2(cos(angle), sin(angle)) * speed, M_PI / 2));
//                 //op.back.setAcc(op.back().getVel() * 0.02);
//             }
//         };

//         auto lmdUpdate = [&](Event *pE) {
//             for (auto &o : op)
//             {
//                 o.setVel(lmdSpinVec2(o.getVel(), M_PI / 80));
//                 //o.setAcc(o.getVel() * sin(pE->getElapsedFrame()));
//                 o.update();
//             }
//         };

//         auto lmdEnd = [&](Event *pE) {
//             op.clear();
//         };

//         Event e(0.5, EventType::eOnce, lmdStart, lmdUpdate, lmdEnd);
//         waitingEvents.push(e);
//     }

//     {
//         constexpr int per = 4;

//         auto &line = bc[eB1];
//         auto &line2 = bc[eB2];

//         auto lmdStart = [&](Event *pE) {
//             line.reserve(500);
//             line2.reserve(500);
//         };

//         auto lmdUpdate = [&](Event *pE) {
//             const auto f = pE->getElapsedFrame();
//             if (!(f % per))
//                 for (int i = 0; i < bc[eOP].size(); ++i)
//                 {
//                     line.emplace_back();
//                     auto &b = line.back();
//                     const auto &op = bc[eOP][i];
//                     b.setPos(op.getPos());
//                     //b.setVel(lmdSpinVec2((enemy.getPos() - op.getPos()) * 0.02, M_PI / 180 * f));
//                     b.setAcc(lmdSpinVec2((enemy.getPos() - op.getPos()).normalize() * 2, M_PI / 180 * f) * 0.012);

//                     line2.emplace_back();
//                     auto &b2 = line2.back();
//                     b2.setTexture(Texture(U"resources/Assets/Bullet_RectangleW.png"));
//                     b2.setPos(op.getPos());
//                     b2.setVel((enemy.getPos() - op.getPos()).normalize() * 3);
//                 }

//             for (auto &b : line)
//             {
//                 //b.setVel(lmdSpinVec2(b.getVel(), -M_PI / 720));
//                 //b.setAcc(b.getVel() * -0.0025);
//                 b.update();
//             }

//             for (auto &b : line2)
//             {
//                 //b.setVel(lmdSpinVec2(b.getVel(), -M_PI / 720));
//                 //b.setAcc(b.getVel() * -0.0025);
//                 b.update();
//             }

//             auto lmdErase = [&](const Bullet &b) {
//                 const Vec2 &pos = b.getPos();
//                 return pos.x < -100 ||
//                        pos.x > windowSize.x + 100 ||
//                        pos.y < -200 ||
//                        pos.y > windowSize.y + 100;
//             };

//             {
//                 auto itr = std::remove_if(line.begin(), line.end(), lmdErase);
//                 line.erase(itr, line.end());
//                 auto itr2 = std::remove_if(line2.begin(), line2.end(), lmdErase);
//                 line2.erase(itr2, line2.end());
//             }
//         };

//         auto lmdEnd = [&](Event *pE) {
//             line.clear();
//             line2.clear();
//         };

//         Event e(1.5, EventType::eOnce, lmdStart, lmdUpdate, lmdEnd);
//         waitingEvents.push(e);
//     }
// }