#include "Bullet.hpp"
#include "CommonConstant.hpp"

Bullet::Bullet()
{
	pos = std::move(Vec2(0, 0));
	vel = std::move(Vec2(0, 0));
	acc = std::move(Vec2(0, 0));
	angle = std::move(0);
	tex = std::move(Texture(U"Assets/Bullet_RectangleB.png"));
}

void Bullet::update()
{
	pos += vel += acc;
	angle = atan(vel.y / vel.x);
}

void Bullet::draw() const
{
	tex.rotated(angle + M_PI / 2).drawAt(pos);
}
