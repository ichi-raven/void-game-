#pragma once
#include <Siv3D.hpp>

struct  Enemy
{
	Enemy()
		: pos(Vec2(0, 0))
		, vel(Vec2(0, 0))
		, acc(Vec2(0, 0))
		, tex(U"Assets/Enemy_1B.png")
	{

	}

	double speed;
	Vec2 pos;
	Vec2 vel;
	Vec2 acc;
	Texture tex;

};