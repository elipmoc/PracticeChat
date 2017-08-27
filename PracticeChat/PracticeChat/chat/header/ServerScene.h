#pragma once
#include "chat\header\SceneBase.hpp"

class ServerScene : public chat::MySceneBase
{
	const siv::Font font;
	siv::GUI gui;

public:
	ServerScene() :font(10) {}

	void init() override
	{
		gui = siv::GUI(siv::GUIStyle::Default);

		gui.add(L"bt1", siv::GUIButton::Create(L"OK"));
		gui.add(L"bt2", siv::GUIButton::Create(L"Cansel"));

		gui.setCenter(siv::Window::Center());

	}

	void update() override
	{
		if (gui.button(L"bt1").pushed)
			changeScene(L"Room");
		if (gui.button(L"bt2").pushed)
			siv::System::Exit();
	}

	void draw() const override
	{
		font(L"ログインシーン表示").draw();

	}
};
