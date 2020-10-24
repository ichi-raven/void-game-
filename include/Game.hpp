#pragma once
#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "GameParam.hpp"

#include "MyShip.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include "Event.hpp"
#include "ScoreLoader.hpp"

#include <vector>
#include <queue>


class Game : public SceneManager<String, GameParam>::Scene
{
public:

	Game(const IScene::InitData& initData) : IScene(initData)
		, font(30)
		, myShip()
		, enemy()
		, time(0)
		, windowSize(Vec2(getData().windowWidth, getData().windowHeight))
		, music(U"resources/Music/Burst.mp3")//テスト音源
	{
		init();
	}

	void init();

	void eventSetup();

	void eventHandle();

	void checkInput();

	void checkCollide();

	void update() override;

	void draw() const override;

private:

	const Vec2			windowSize;
	const Font			font;
	MyShip				myShip;
	Enemy				enemy;
	std::vector<Event>  activeEvents;
	std::vector<Event>	waitingEvents;
	const Audio			music;
	double				time;
	Timer				hitTimer;
	ScoreLoader 		scoreLoader;
	std::vector<Note> 	notes;

	Rect mProgressBar;
};