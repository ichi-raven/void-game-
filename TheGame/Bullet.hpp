#pragma once
#include <Siv3D.hpp>

struct Bullet
{
	Bullet()
		: pos(Vec2(0, 0))
		, vel(Vec2(0, 0))
		, acc(Vec2(0, 0))
		, angle(0)
		, tex(U"Assets/Bullet_RectangleB.png")
	{

	}

	Vec2 pos;
	Vec2 vel;
	Vec2 acc;
	double angle;

	Texture tex;

};