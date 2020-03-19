#include "Object.hpp"
#include "CommonConstant.hpp"


void Object::setPos(const Vec2& pos)
{
	mPos = pos;
}

Vec2 Object::getPos() const
{
	return mPos;
}

void Object::setVel(const Vec2& vel)
{
	mVel = vel;
}

Vec2 Object::getVel() const
{
	return mVel;
}

void Object::setAcc(const Vec2& acc)
{
	mAcc = acc;
}

Vec2 Object::getAcc() const
{
	return mAcc;
}

double Object::getAngle() const
{
	return mAngle;
}

void Object::update()
{
	mPos += mVel += mAcc;

	if (mVel.x == 0)
	{
		mAngle = mVel.y >= 0 ? M_PI / 2 : -M_PI / 2;
		return;
	}

	mAngle = atan(mVel.y / mVel.x);
}

