#include "MyShip.hpp"
#include "CommonConstant.hpp"

MyShip::MyShip()
{
	mPos = std::move(Vec2(0, 0));
	mVel = std::move(Vec2(0, 0));
	mAcc = std::move(Vec2(0, 0));
	mAngle = std::move(0);
	mTex = std::move(Texture(U"resources/Assets/MyShip_Black.png"));
	mFont = std::move(Font(15));
	mHitFlag = false;
	mHitFrame = 0;
	mLife = 3;
}

void MyShip::update()
{
	Object::update();

	--mHitFrame;
	if (mHitFrame == 0)
	{
		mHitFlag = false;
	}
}

void MyShip::draw(const Vec2& windowSize) const
{
	if(mHitFlag && mHitFrame % 20 < 10)
		return;
	mTex.drawAt(mPos);

	mFont(U"Life : {}"_fmt(mLife)).drawAt(Vec2(windowSize.x / 10 * 9 - 10, windowSize.y / 3 * 2));
}

void MyShip::hit()
{
	if(mHitFlag)
		return;

	--mLife;
	mHitFlag = true;
	mHitFrame = 180;

}

bool MyShip::isDead()
{
	return mLife == 0;
}