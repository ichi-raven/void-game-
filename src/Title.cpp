#include "Title.hpp"

void Title::update()
{
	if (KeyEnter.down())
		changeScene(U"Game");
}

void Title::draw() const
{
	Vec2 pos(getData().windowWidth / 2, getData().windowHeight / 2);

	font(U"PRESS ENTER").drawAt(pos);

}