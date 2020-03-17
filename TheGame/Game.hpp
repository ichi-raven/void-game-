#pragma once
#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "GameParam.hpp"

#include "MyShip.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include "Event.hpp"

#include <vector>
#include <queue>

using BC = std::unordered_map<int, std::vector<Bullet>>;

class Game : public SceneManager<String, GameParam>::Scene
{
public:

	Game(const IScene::InitData& initData) : IScene(initData)
		, font(30)
		, myShip()
		, enemy()
		, time(0)
		, windowSize(Vec2(getData().windowWidth, getData().windowHeight))
		, music(U"Assets/Lo-fi試作2.wav")
	{
		init();
	}

	void init();

	void BCSetup();

	void eventSetup();

	void eventHandle();

	void input();//入力に関する処理はここ

	void update() override;

	void draw() const override;


private:

	const Vec2			windowSize;
	const Font			font;
	MyShip				myShip;
	Enemy				enemy;
	BC					bc;
	std::vector<Event>  activeEvents;
	std::queue<Event>	waitingEvents;
	const Audio			music;
	double				time;
};