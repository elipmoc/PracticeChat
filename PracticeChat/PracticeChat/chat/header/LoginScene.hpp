#pragma once
#include "chat\header\SceneBase.hpp"

namespace chat {
	/* �N������ɌĂ΂��V�[�� */
	class LoginScene : public MySceneBase
	{
		siv::GUI gui;

	public:

		void init() override
		{
			gui = siv::GUI(siv::GUIStyle::Default);

			//���[�U�[���̓��͗�
			gui.addln(siv::GUIText::Create(L"���[�U�[��"));
			gui.addln(L"userName", siv::GUITextField::Create(10));

			//�{�^��
			gui.add(L"create", siv::GUIButton::Create(L"�����쐬"));
			gui.add(L"login", siv::GUIButton::Create(L"����"));

			gui.setCenter(siv::Window::Center());

		}

		void update() override
		{
			//IME�̈ʒu�ύX
			if (gui.textField(L"userName").active)
				siv::IME::SetCompositionWindowPos(gui.getPos() + siv::Point(25,48));

			if (gui.button(L"login").pushed)
				LoginPush();
			if (gui.button(L"create").pushed)
				CreatePush();
		}

		void draw() const override
		{
			m_data->font(L"���O�C���V�[���\��").draw();
		}

		//Login�{�^�������������̊֐�
		void LoginPush()
		{
			//���[�U�[�l�[������
			m_data->userName.assign(gui.textField(L"userName").text);
			changeScene(L"Server");
		}

		//Create�{�^�������������̊֐�
		void CreatePush()
		{
			//���[�U�[�l�[������
			m_data->userName.assign(gui.textField(L"userName").text);
			changeScene(L"Create");
		}
	};
}