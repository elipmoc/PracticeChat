#pragma once
#include "chat\header\SceneBase.hpp"

class RoomScene : public chat::MySceneBase
{
	const siv::Font font;
	public:
		RoomScene():font(10){}

	void init() override
	{

	}

	void update() override
	{

	}

	void draw() const override
	{
		font(L"テストシーン表示").draw();

	}
};
