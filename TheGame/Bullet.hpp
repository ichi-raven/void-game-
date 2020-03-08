#pragma once
#include <Siv3D.hpp>

struct Bullet
{
	Bullet();

	void update();

	void draw() const;

	Vec2 pos;
	Vec2 vel;
	Vec2 acc;
	double angle;

	Texture tex;

};