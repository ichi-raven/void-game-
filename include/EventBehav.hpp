#pragma once

#include <Siv3D.hpp>

class Object;

class Enemy;
class MyShip;
class Bullet;

using BC = std::unordered_map<int, std::vector<Bullet>>;

class EventBehav
{
public:
    virtual void init(Enemy &enemy, MyShip &myship, const Vec2& windowSize) = 0; //初期化

    virtual void update(Enemy &enemy, MyShip &myship, const double &elapsedTime) = 0; //更新

    virtual void draw() const = 0;//描画

    virtual bool end() = 0;//trueを返すと終了する

    virtual bool checkHit(MyShip& myShip) = 0;//持つオブジェクトに対してヒット判定を行う

protected:
    BC bc;
    Vec2 mWindowSize;
};