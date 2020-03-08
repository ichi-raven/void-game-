#include "MyShip.hpp"
#include "CommonConstant.hpp"

MyShip::MyShip()
{
	pos = std::move(Vec2(0, 0));
	vel = std::move(Vec2(0, 0));
	acc = std::move(Vec2(0, 0));
	angle = std::move(0);
	tex = std::move(Texture(U"Assets/MyShip_Black.png"));
}

void MyShip::update()
{
	pos += vel += acc;
	angle = atan(vel.y / vel.x);
}

void MyShip::draw() const
{
	tex.rotated(angle + M_PI / 2).drawAt(pos);
}
