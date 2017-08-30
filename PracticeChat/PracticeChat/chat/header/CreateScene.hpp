#pragma once
#include "chat\header\SceneBase.hpp"

namespace chat {
	class CreateScene : public MySceneBase
	{
		siv::GUI gui;

	public:

		void init() override
		{
			gui = siv::GUI(siv::GUIStyle::Default);

			//ユーザー名の入力欄
			gui.addln(siv::GUIText::Create(L"Port番号"));
			gui.addln(L"portNumber", siv::GUITextField::Create(11));
			
			//ボタン
			gui.add(L"create", siv::GUIButton::Create(L"部屋作成"));
			gui.add(L"logout", siv::GUIButton::Create(L"ログアウト"));

			gui.setCenter(siv::Window::Center());

		}

		void update() override
		{
			//IMEの位置変更
			if (gui.textField(L"portNumber").active)
				siv::IME::SetCompositionWindowPos(gui.getPos() + siv::Point(25, 48));

			if (gui.button(L"create").pushed)
				CreatePush();
			if (gui.button(L"logout").pushed)
				LogoutPush();
		}

		void draw() const override
		{
			m_data->font(L"クリエイトシーン表示").draw();
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
}