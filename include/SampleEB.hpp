#pragma once

#include "EventBehav.hpp"

#include <vector>
#include <unordered_map>

class Bullet;
class Enemy;
class MyShip;

class SampleEB : public EventBehav
{
public:
    virtual void init(Enemy &enemy, MyShip &myship, const Vec2& windowSize); //初期化

    virtual void update(Enemy &enemy, MyShip &myship, const double &elapsedTime); //更新

    virtual void draw() const; //描画

    virtual bool end(); //trueを返すと終了する

    virtual bool checkHit(MyShip &myShip); //持つオブジェクトに対してヒット判定を行う


};