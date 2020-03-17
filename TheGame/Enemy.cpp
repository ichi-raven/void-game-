#include "Enemy.hpp"
#include "CommonConstant.hpp"


Enemy::Enemy()
{
	mPos = std::move(Vec2(0, 0));
	mVel = std::move(Vec2(0, 0));
	mAcc = std::move(Vec2(0, 0));
	mAngle = std::move(0);
	mTex = std::move(Texture(U"Assets/Enemy_2B.png"));
}

void Enemy::update()
{
	Object::update();
}

void Enemy::draw() const
{
	mTex.drawAt(mPos);
}
