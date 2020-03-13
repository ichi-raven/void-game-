#pragma once
#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "GameParam.hpp"

#include "MyShip.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include "Event.hpp"

class Game : public SceneManager<String, GameParam>::Scene
{
public:

	Game(const IScene::InitData& initData) : IScene(initData)
		, font(30)
		, myShip()
		, enemy()
		, time(0)
		, windowSize(Vec2(getData().windowWidth, getData().windowHeight))
		, music(U"Assets/å∂ëzèÚó⁄óû.wav")
	{
		init();
	}

	void init();

	void update() override;

	void draw() const override;

	void input_update();

	void enemy_update();

	void BC_update();

	void time_update();

	void event_update();

private:
	const Vec2			windowSize;

	const Font			font;
	MyShip				myShip;
	Enemy				enemy;
	std::vector<Bullet> bc;
	std::vector<Event>  events;

	const Audio			music;
	double				time;
};