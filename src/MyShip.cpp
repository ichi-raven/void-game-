#include "MyShip.hpp"
#include "CommonConstant.hpp"

MyShip::MyShip()
{
	mPos = std::move(Vec2(0, 0));
	mVel = std::move(Vec2(0, 0));
	mAcc = std::move(Vec2(0, 0));
	mAngle = std::move(0);
	mTex = std::move(Texture(U"resources/Assets/MyShip_Black.png"));
}

void MyShip::update()
{
	Object::update();
}

void MyShip::draw() const
{
	mTex.drawAt(mPos);
}
