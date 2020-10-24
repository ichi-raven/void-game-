#include "Result.hpp"

void Result::update()
{
    if (KeyEnter.down())
        changeScene(U"Title");
}

void Result::draw() const
{
    const Vec2 &window = Vec2(getData().windowWidth, getData().windowHeight);
    Vec2 pos(window.x / 2, window.y / 2);

    if(getData().endWithDead)
        font(U"GAME OVER!").drawAt(Vec2(window.x / 2, window.y / 3));
    else
        font(U"YOU CLEARED!").drawAt(Vec2(window.x / 2, window.y / 3));

    font(U"PRESS ENTER TO RETURN TO TITLE").drawAt(window.x / 2, window.y / 5 * 4);
}