#pragma once
#include "chat\header\SceneBase.hpp"

namespace chat {
	class ServerScene : public MySceneBase
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
			gui.addln(L"ipAddress", siv::GUITextArea::Create(1, 10));

			//ボタン
			gui.add(L"serverIn", siv::GUIButton::Create(L"ServerIn"));
			gui.add(L"logout", siv::GUIButton::Create(L"LogOut"));

			gui.setCenter(siv::Window::Center());

		}

		void update() override
		{
			if (gui.button(L"serverIn").pushed)
				ServerInPush();
			if (gui.button(L"logout").pushed)
				LogoutPush();

		}

		void draw() const override
		{
			font(L"サーバーシーン表示").draw();

		}

		//ServerInボタンを押した時の関数
		void ServerInPush()
		{
			changeScene(L"Room");
		}

		//Logoutボタンを押した時の関数
		void LogoutPush()
		{
			changeScene(L"Login");
		}
	};
}