#include "SampleEB.hpp"

#include "Bullet.hpp"
#include "Object.hpp"

#include "Enemy.hpp"
#include "MyShip.hpp"

enum BCIndex
{
    eOP,
    eLine1,
    eLine2,
    eCircle
};

constexpr auto lmdSpinVec2 = [](const Vec2 &v, const double &angle) -> Vec2 
{
    return Vec2(v.x * cos(angle) - v.y * sin(angle),
                v.x * sin(angle) + v.y * cos(angle));
};

void SampleEB::init(Enemy &enemy, MyShip &myship, const Vec2& windowSize)
{
    mWindowSize = windowSize;
    bc.emplace(eCircle, std::vector<Bullet>());

    constexpr int NumOnce = 12;
    constexpr double radius = 100;
    constexpr double speed = 5;
    auto &op = bc[eCircle];

    for (int i = 0; i < NumOnce; ++i)
    {
        op.emplace_back();
        op.back().setTexture(Texture(U"resources/Assets/Bullet_CircleW.png"));
        op.back().setScale(Vec2(1.3, 1.3));
        const double angle = 2 * M_PI / NumOnce * i;
        op.back().setPos(enemy.getPos() + Vec2(cos(angle), sin(angle)) * radius);
        //op.back().setVel(lmdSpinVec2(Vec2(cos(angle), sin(angle)) * speed, M_PI / 9));
        op.back().setVel(Vec2(cos(angle), sin(angle)) * speed);
        //op.back().setAcc(op.back().getVel() * -0.02);
    }
}

void SampleEB::update(Enemy &enemy, MyShip &myship, const double &elapsedTime)
{
    for (auto &o : bc[eCircle])
    {
        //if(o.getVel().length() >= 7)
            //o.setVel(lmdSpinVec2(o.getVel(), -M_PI / 180));
        //o.setAcc(o.getVel() * sin(pE->getElapsedFrame()));
        o.update();
    }

    auto lmdErase = [&](const Bullet &b) 
    {
        const Vec2 &pos = b.getPos();
        return pos.x < -100 ||
        pos.x > mWindowSize.x + 100 ||
        pos.y < -200 ||
        pos.y > mWindowSize.y + 100;
    };

    bc[eCircle].erase(std::remove_if(bc[eCircle].begin(), bc[eCircle].end(), lmdErase), bc[eCircle].end());
}

void SampleEB::draw() const
{
        for (auto &bvp : bc)
            for (auto &b : bvp.second)
                b.draw();
}

bool SampleEB::end()
{
    bool rtn = true;
    for (auto &bvp : bc)
        rtn &= bvp.second.empty();

    return rtn;
}

bool SampleEB::checkHit(MyShip& myShip)
{
    for (const auto &bVecPair : bc)
        for (const auto &b : bVecPair.second)
        {
            //範囲制限による高速化、再考の余地あり
            if (b.getPos().x < myShip.getPos().x - 100 ||
                b.getPos().x > myShip.getPos().x + 100 ||
                b.getPos().y < myShip.getPos().y - 100 ||
                b.getPos().y > myShip.getPos().y + 100)
                continue;

            //衝突時のことを考えてない
            if (myShip.getPos().distanceFrom(b.getPos()) <= 10)
            {
                myShip.hit();
                return true;
            }
        }

    return false;
}