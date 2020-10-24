#pragma once
#include <Siv3D.hpp>
#include "Object.hpp"

class MyShip : public Object
{
public:

	MyShip();

	void update();

	void draw(const Vec2& windowSize) const;

	void hit();//被弾した

	bool isDead();//ゲームオーバー

private:
	bool mHitFlag;
	int mHitFrame;
	int mLife;
	Texture mTex;
	Font mFont;
};
