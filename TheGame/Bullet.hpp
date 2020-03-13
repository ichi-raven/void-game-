#pragma once
#include <Siv3D.hpp>
#include "Object.hpp"

struct Bullet : public Object
{
	Bullet();

	void update();

	void draw() const;

private:

	double angle;

	Texture tex;

};