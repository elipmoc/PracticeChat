#pragma once
#include "chat\header\SceneBase.hpp"

namespace chat {
	/* 起動直後に呼ばれるシーン */
	class LoginScene : public MySceneBase
	{
		siv::GUI gui;

	public:

		void init() override
		{
			gui = siv::GUI(siv::GUIStyle::Default);

			//ユーザー名の入力欄
			gui.addln(siv::GUIText::Create(L"ユーザー名"));
			gui.addln(L"userName", siv::GUITextField::Create(10));

			//ボタン
			gui.add(L"create", siv::GUIButton::Create(L"部屋作成"));
			gui.add(L"login", siv::GUIButton::Create(L"入室"));

			gui.setCenter(siv::Window::Center());

		}

		void update() override
		{
			//IMEの位置変更
			if (gui.textField(L"userName").active)
				siv::IME::SetCompositionWindowPos(gui.getPos() + siv::Point(25,48));

			if (gui.button(L"login").pushed)
				LoginPush();
			if (gui.button(L"create").pushed)
				CreatePush();
		}

		void draw() const override
		{
			m_data->font(L"ログインシーン表示").draw();
		}

		//Loginボタンを押した時の関数
		void LoginPush()
		{
			//ユーザーネームを代入
			m_data->userName.assign(gui.textField(L"userName").text);
			changeScene(L"Server");
		}

		//Createボタンを押した時の関数
		void CreatePush()
		{
			//ユーザーネームを代入
			m_data->userName.assign(gui.textField(L"userName").text);
			changeScene(L"Create");
		}
	};
}