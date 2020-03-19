#pragma once
#include <Siv3D.hpp>

class Object
{
public:

	void setPos(const Vec2& pos);
	Vec2 getPos() const;

	void setVel(const Vec2& vel);
	Vec2 getVel() const;

	void setAcc(const Vec2& acc);
	Vec2 getAcc() const;

	double getAngle() const;

	void update();

protected:
	Vec2	mPos;
	Vec2	mVel;
	Vec2	mAcc;
	double	mAngle;
};