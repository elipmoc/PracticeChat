#pragma once
#include "chat\header\SceneBase.hpp"

namespace chat {
	class RoomScene : public MySceneBase
	{
		const siv::Font font;
		siv::GUI gui;

	public:
		RoomScene() :font(10) {}

		void init() override
		{
			gui = siv::GUI(siv::GUIStyle::Default);
			//ユーザーネーム
			gui.add(siv::GUIText::Create(L"ユーザー名"));
			gui.addln(L"userName", siv::GUITextArea::Create(1, 10));

			//ボタン
			gui.addln(L"serverOut", siv::GUIButton::Create(L"ServerOut"));

			gui.add(L"hr1", siv::GUIHorizontalLine::Create(1));

			//チャット欄
			gui.addln(L"chatMain", siv::GUITextArea::Create(10, 20));

			gui.add(L"hr2", siv::GUIHorizontalLine::Create(1));

			//メッセージ入力欄
			gui.add(L"message", siv::GUITextArea::Create(1, 10));
			//送信ボタン
			gui.addln(L"send", siv::GUIButton::Create(L"送信"));

			//色コード欄
			gui.add(L"color", siv::GUITextArea::Create(1, 5));
			//エフェクト
			gui.add(L"effect", siv::GUICheckBox::Create({ L"Bold",L"Italic" }));

			gui.setCenter(siv::Window::Center());
		}

		void update() override
		{
			if (gui.button(L"serverOut").pushed)
				ServerOutPush();
			if (gui.button(L"send").pushed)
				SendPush();
		}

		void draw() const override
		{
			font(L"ルームシーン表示").draw();

		}

		//ServerOutボタンを押した時の関数
		void ServerOutPush()
		{
			changeScene(L"Login");
		}

		//Sendボタンを押した時の関数
		void SendPush()
		{

		}


	};
}