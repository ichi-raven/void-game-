#pragma once
#include <Siv3D.hpp>
#include "Object.hpp"

class Bullet : public Object
{
public:

	Bullet();

	void setTexture(const Texture& tex);

	void setScale(const Vec2& scale);

	void setState(const uint8_t state);

	uint8_t getState() const;

	void update();

	void draw() const;

private:

	Texture mTex;
	Vec2 mScale;
	uint8_t mState;
};