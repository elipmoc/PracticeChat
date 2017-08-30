#pragma once
#include "chat\header\SceneBase.hpp"

namespace chat {
	class ServerScene : public MySceneBase
	{
		siv::GUI gui;

	public:

		void init() override
		{
			gui = siv::GUI(siv::GUIStyle::Default);

			//IPv4の入力欄
			gui.add(siv::GUIText::Create(L"IPv4"));
			gui.addln(L"ipAddress", siv::GUITextField::Create(11));

			//ボタン
			gui.add(L"serverIn", siv::GUIButton::Create(L"入室"));
			gui.add(L"logout", siv::GUIButton::Create(L"ログアウト"));

			gui.setCenter(siv::Window::Center());

		}

		void update() override
		{
			//IMEの位置変更
			if (gui.textField(L"ipAddress").active)
				siv::IME::SetCompositionWindowPos(gui.getPos() + siv::Point(67, 17));

			if (gui.button(L"serverIn").pushed)
				ServerInPush();
			if (gui.button(L"logout").pushed)
				LogoutPush();

		}

		void draw() const override
		{
			m_data->font(L"サーバーシーン表示").draw();

		}

		//ServerInボタンを押した時の関数
		void ServerInPush()
		{
			m_data->ipAddress.assign(gui.textField(L"ipAddress").text);
			changeScene(L"Room");
		}

		//Logoutボタンを押した時の関数
		void LogoutPush()
		{
			changeScene(L"Login");
		}
	};
}