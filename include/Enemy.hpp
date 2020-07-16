#pragma once
#include <Siv3D.hpp>
#include "Object.hpp"

class Enemy : public Object
{
public:

	Enemy();

	void update();

	void draw() const;

	void setTexture(Texture tex);

private:

	Texture mTex;
};