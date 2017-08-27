#pragma once
#include "chat\header\SceneBase.hpp"

class RoomScene : public chat::MySceneBase
{
	const siv::Font font;
	siv::GUI gui;

	public:
		RoomScene():font(10){}

	void init() override
	{
		gui = siv::GUI(siv::GUIStyle::Default);

		gui.add(L"bt1", siv::GUIButton::Create(L"不要物"));
		gui.add(L"bt2", siv::GUIButton::Create(L"ServerOut"));
		
		gui.setCenter(siv::Window::Center());

	}

	void update() override
	{
		if (gui.button(L"bt2").pushed)
			changeScene(L"Server");

	}

	void draw() const override
	{
		font(L"ルームシーン表示").draw();

	}
};
