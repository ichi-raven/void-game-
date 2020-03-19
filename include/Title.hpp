#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "GameParam.hpp"

class Title : public SceneManager<String, GameParam>::Scene
{
public:

	Title(const IScene::InitData& initData) : IScene(initData)
	, font(30)
	{

	}

	void update() override;

	void draw() const override;

private:
	const Font font;
};