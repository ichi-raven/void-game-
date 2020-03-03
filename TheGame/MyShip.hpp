#pragma once
#include <Siv3D.hpp>

struct  MyShip
{
	MyShip()
		: pos(Vec2(0, 0))
		, vel(Vec2(0, 0))
		, acc(Vec2(0, 0))
		, tex(U"Assets/MyShip_Black.png")
	{

	}

	Vec2 pos;
	Vec2 vel;
	Vec2 acc;
	Texture tex;

};