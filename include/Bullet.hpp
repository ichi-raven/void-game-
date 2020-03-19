#pragma once
#include <Siv3D.hpp>
#include "Object.hpp"

class Bullet : public Object
{
public:

	Bullet();

	void setTexture(const s3d::FilePath& path);

	void update();

	void draw() const;

private:

	Texture mTex;

};