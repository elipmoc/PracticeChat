#pragma once
#include "chat\header\SceneBase.hpp"
#include "Experiment\TestElipmoc.hpp"

namespace chat {
	class ServerScene : public MySceneBase
	{
		siv::GUI gui;

	public:

		void init() override
		{
			gui = siv::GUI(siv::GUIStyle::Default);

			//IPv4�̓��͗�
			gui.add(siv::GUIText::Create(L"IPv4"));
			gui.addln(L"ipAddress", siv::GUITextField::Create(11));

			//�{�^��
			gui.add(L"serverIn", siv::GUIButton::Create(L"����"));
			gui.add(L"logout", siv::GUIButton::Create(L"���O�A�E�g"));

			gui.setCenter(siv::Window::Center());

		}

		void update() override
		{
			//IME�̈ʒu�ύX
			if (gui.textField(L"ipAddress").active)
				siv::IME::SetCompositionWindowPos(gui.getPos() + siv::Point(67, 17));

			if (gui.button(L"serverIn").pushed)
				ServerInPush();
			if (gui.button(L"logout").pushed)
				LogoutPush();

		}

		void draw() const override
		{
			m_data->font(L"�T�[�o�[�V�[���\��").draw();

		}

		//ServerIn�{�^�������������̊֐�
		void ServerInPush()
		{
			m_data->ipAddress.assign(gui.textField(L"ipAddress").text);
			changeScene(L"Room");
		}

		//Logout�{�^�������������̊֐�
		void LogoutPush()
		{
			changeScene(L"Login");
		}
	};
}