#include "Enemy.hpp"
#include "CommonConstant.hpp"


Enemy::Enemy()
{

	mPos = Vec2(0, 0);
	mVel = Vec2(0, 0);
	mAcc = Vec2(0, 0);
	mAngle = 0;
	mTex = Texture(U"resources/Assets/Enemy_2B.png");

}

void Enemy::update()
{
	Object::update();
}

void Enemy::draw() const
{
	mTex.drawAt(mPos);
}

void Enemy::setTexture(Texture tex)
{
	mTex = tex;
}