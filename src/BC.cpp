#include "BC.hpp"
#include "Bullet.hpp"
#include "CommonConstant.hpp"

BC::BC()
{

}


void BC::update(std::function<bool(const Bullet & b)> lmdErase)
{
	

	//çXêV
	for(auto& bc : bulletMap)
		for (auto& b : bc.second)
			b.update();

	//çÌèú
	for (auto& bc : bulletMap)
		bc.second.erase
		(
			std::remove_if(bc.second.begin(), bc.second.end(), lmdErase)
			, bc.second.end()
		);
}

void BC::draw() const
{
	for (const auto& bc : bulletMap)
		for (const auto& b : bc.second)
			b.draw();
}

bool BC::isCollide(const Vec2& other, const double& size) const
{
	for (const auto& bc : bulletMap)
		for (const auto& b : bc.second)
			if (b.getPos().distanceFrom(other) <= size)
				return true;

	return false;
}

void BC::reset()
{
	for (auto& bc : bulletMap)
		bc.second.clear();
}