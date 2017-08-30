#pragma once
#include "chat\header\SceneBase.hpp"

namespace chat {
	class LoginScene : public MySceneBase
	{
		const siv::Font font;
		siv::GUI gui;

	public:
		LoginScene() :font(10) {}

		void init() override
		{
			gui = siv::GUI(siv::GUIStyle::Default);

			//ユーザー名の入力欄
			gui.addln(siv::GUIText::Create(L"ユーザー名"));
			gui.addln(L"userName", siv::GUITextArea::Create(1, 10));

			//ボタン
			gui.add(L"create", siv::GUIButton::Create(L"部屋作成"));
			gui.add(L"login", siv::GUIButton::Create(L"入室"));

			gui.setCenter(siv::Window::Center());

		}

		void update() override
		{
			//if (gui.)
			if (gui.button(L"login").pushed)
				LoginPush();
			if (gui.button(L"create").pushed)
				CreatePush();
		}

		void draw() const override
		{
			font(L"ログインシーン表示").draw();
		}

		//Loginボタンを押した時の関数
		void LoginPush()
		{
			changeScene(L"Server");

		}

		//Createボタンを押した時の関数
		void CreatePush()
		{
			changeScene(L"Create");
		}
	};
}