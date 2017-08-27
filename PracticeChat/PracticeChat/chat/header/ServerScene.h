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

		//IPv4の入力欄
		gui.add(siv::GUIText::Create(L"IPv4"));
		gui.addln(L"ta1", siv::GUITextArea::Create(1,10));

		//ボタン
		gui.add(L"bt1", siv::GUIButton::Create(L"ServerIn"));
		gui.add(L"bt2", siv::GUIButton::Create(L"LogOut"));

		gui.setCenter(siv::Window::Center());

	}

	void update() override
	{
		if (gui.button(L"bt1").pushed)
			changeScene(L"Room");
		if (gui.button(L"bt2").pushed)
			changeScene(L"Login");
	}

	void draw() const override
	{
		font(L"サーバーシーン表示").draw();

	}
};
