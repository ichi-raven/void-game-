#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "GameParam.hpp"

class Result : public SceneManager<String, GameParam>::Scene
{
public:
    Result(const IScene::InitData &initData) : IScene(initData), font(30)
    {
    }

    void update() override;

    void draw() const override;

private:
    const Font font;
};