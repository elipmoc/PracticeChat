#pragma once
#include "chat\header\SceneBase.hpp"
#include "Experiment\\ATH\ServerTest.hpp"

namespace chat {
	class RoomScene : public MySceneBase
	{
		experiment::ATH::ServerTest server;
		siv::GUI gui;
	public:

		void init() override
		{
			server.Init();

			gui = siv::GUI(siv::GUIStyle::Default);
			//ユーザーネーム
			gui.add(siv::GUIText::Create(L"ユーザー名"));
			gui.addln(L"userName", siv::GUITextField::Create(10));

			//ボタン
			gui.addln(L"serverOut", siv::GUIButton::Create(L"退室"));

			gui.add(L"hr1", siv::GUIHorizontalLine::Create(1));

			//チャット欄
			gui.addln(L"chatMain", siv::GUITextArea::Create(10, 25));

			gui.add(L"hr2", siv::GUIHorizontalLine::Create(1));

			//メッセージ入力欄
			gui.add(L"message", siv::GUITextField::Create(14));
			//送信ボタン
			gui.addln(L"send", siv::GUIButton::Create(L"送信"));

			//色コード欄
			gui.add(L"color", siv::GUITextField::Create(7));
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
			m_data->font(L"ルームシーン表示").draw();
		}

		//ServerOutボタンを押した時の関数
		void ServerOutPush()
		{
			changeScene(L"Login");
		}

		//Sendボタンを押した時の関数
		void SendPush()
		{
			s3d::String str = gui.textField(L"message")._get_text();
			server.SendMessage(str.narrow());
			s3d::Println(str);
		}
	};
}