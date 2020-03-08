#pragma once
#include <Siv3D.hpp>

class Enemy
{
public:

	Enemy();

	void update();

	void draw() const;

	Vec2 pos;
	Vec2 vel;
	Vec2 acc;
	double angle;

	Texture tex;

};