#pragma once
#include "chat\header\SceneBase.hpp"

class CreateScene : public chat::MySceneBase
{
	const siv::Font font;
	siv::GUI gui;

public:
	CreateScene() :font(10) {}

	void init() override
	{
		gui = siv::GUI(siv::GUIStyle::Default);

		//ユーザー名の入力欄
		gui.addln(siv::GUIText::Create(L"Port番号"));
		gui.addln(L"portNumber", siv::GUITextArea::Create(1, 10));

		//ボタン
		gui.add(L"create", siv::GUIButton::Create(L"ServerCreate"));
		gui.add(L"logout", siv::GUIButton::Create(L"LogOut"));

		gui.setCenter(siv::Window::Center());

	}

	void update() override
	{
		if (gui.button(L"create").pushed)
			CreatePush();
		if (gui.button(L"logout").pushed)
			LogoutPush();
	}

	void draw() const override
	{
		font(L"クリエイトシーン表示").draw();
	}
	
	//Createボタンを押した時の関数
	void CreatePush()
	{
		changeScene(L"Room");
	}

	//LogOutボタンを押した時の関数
	void LogoutPush()
	{
		changeScene(L"Login");
	}
};
