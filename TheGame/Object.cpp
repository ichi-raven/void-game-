#include "Object.hpp"
#include "CommonConstant.hpp"


void Object::setPos(const Vec2& _pos)
{
	pos = _pos;
}

Vec2 Object::getPos() const
{
	return pos;
}

void Object::setVel(const Vec2& _vel)
{
	vel = _vel;
}

Vec2 Object::getVel() const
{
	return vel;
}

void Object::setAcc(const Vec2& _acc)
{
	acc = _acc;
}

Vec2 Object::getAcc() const
{
	return acc;
}

double Object::getAngle() const
{
	return angle;
}

void Object::update()
{
	pos += vel += acc;
	angle = atan(vel.y / vel.x);
}

