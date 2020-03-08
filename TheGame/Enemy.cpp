#include "Enemy.hpp"
#include "CommonConstant.hpp"


Enemy::Enemy()
{
	pos = std::move(Vec2(0, 0));
	vel = std::move(Vec2(0, 0));
	acc = std::move(Vec2(0, 0));
	angle = std::move(0);
	tex = std::move(Texture(U"Assets/Enemy_2B.png"));
}

void Enemy::update()
{
	pos += vel += acc;
	angle = atan(vel.y / vel.x);
}

void Enemy::draw() const
{
	tex.rotated(angle + M_PI / 2).drawAt(pos);
}