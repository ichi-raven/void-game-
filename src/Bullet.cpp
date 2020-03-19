#include "Bullet.hpp"
#include "CommonConstant.hpp"

Bullet::Bullet()
{
	mPos = std::move(Vec2(0, 0));
	mVel = std::move(Vec2(0, 0));
	mAcc = std::move(Vec2(0, 0));
	mAngle = std::move(0);
	mTex = std::move(Texture(U"resources/Assets/Bullet_RectangleB.png"));
}

void Bullet::setTexture(const s3d::FilePath& path)
{
	mTex = std::move(Texture(path));
}

void Bullet::update()
{
	Object::update();
}

void Bullet::draw() const
{
	mTex.rotated(mAngle + M_PI / 2).drawAt(mPos);
}
