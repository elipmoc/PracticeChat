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
		if (siv::Input::MouseL.clicked)
			changeScene(L"Login");

	}

	void draw() const override
	{
		font(L"ルームシーン表示").draw();

	}
};
