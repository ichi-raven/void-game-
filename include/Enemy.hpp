#pragma once
#include <Siv3D.hpp>
#include "Object.hpp"

class Enemy : public Object
{
public:

	Enemy();

	void update();

	void draw() const;

private:

	Texture mTex;
};