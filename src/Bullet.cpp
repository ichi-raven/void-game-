#include "Bullet.hpp"
#include "CommonConstant.hpp"

Bullet::Bullet()
{
	mPos = Vec2(0, 0);
	mVel = Vec2(0, 0);
	mAcc = Vec2(0, 0);
	mAngle = 0;
	mTex = Texture(U"resources/Assets/Bullet_RectangleB.png");
	mScale = Vec2(1, 1);
	mState = 0;
}

void Bullet::setTexture(const Texture& tex)
{
	mTex = tex;
}

void Bullet::setScale(const Vec2& scale)
{
	mScale = scale;
}

void Bullet::setState(uint8_t state)
{
	mState = state;
}

uint8_t Bullet::getState() const
{
	return mState;
}

void Bullet::update()
{
	Object::update();
}

void Bullet::draw() const
{
	mTex.scaled(mScale).rotated(mAngle + M_PI / 2).drawAt(mPos);
}
