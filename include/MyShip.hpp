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

	Texture mTex;
};

