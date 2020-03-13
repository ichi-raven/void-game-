#pragma once
#include <Siv3D.hpp>
#include "Object.hpp"

class MyShip : public Object
{
public:

	MyShip();

	void update();

	void draw() const;

private:
	double angle;

	Texture tex;
};



//inline void setPos(const Vec2& _pos)
//{
//	pos = _pos;
//}

//inline Vec2 getPos()
//{
//	return pos;
//}

//inline void setVel(const Vec2& _vel)
//{
//	vel = _vel;
//}

//inline Vec2 getVel()
//{
//	return vel;
//}

//inline void setAcc(const Vec2& _acc)
//{
//	acc = _acc;
//}

//inline Vec2 getAcc()
//{
//	return acc;
//}