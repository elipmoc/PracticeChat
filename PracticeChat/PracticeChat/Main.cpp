#include "chat\header\LoginScene.hpp"
#include "chat\header\RoomScene.hpp"
#include "chat\header\ServerScene.hpp"
#include "chat\header\CreateScene.hpp"
#include "tcpframework\test.hpp"

void Main()
{
	chat::MySceneManager sceneManager;

	sceneManager.add<LoginScene>(L"Login");
	sceneManager.add<ServerScene>(L"Server");
	sceneManager.add<RoomScene>(L"Room");
	sceneManager.add<CreateScene>(L"Create");

	siv::Println(tcpframework::TcpManager::Init());
	tcpframework::ServerSocket serverSocket(19132,5);
	siv::Println(serverSocket.Bind());
	siv::Println(serverSocket.Listen());
	auto send=serverSocket.Accept();
	tcpframework::TcpManager::End();
	while (siv::System::Update())
	{
		if (!sceneManager.updateAndDraw())
			break;
	}
}
