#include "chat\header\LoginScene.hpp"
#include "chat\header\RoomScene.hpp"
#include "chat\header\ServerScene.hpp"
#include "chat\header\CreateScene.hpp"


void Main()
{
	chat::MySceneManager sceneManager;

	sceneManager.add<LoginScene>(L"Login");
	sceneManager.add<ServerScene>(L"Server");
	sceneManager.add<RoomScene>(L"Room");
	sceneManager.add<CreateScene>(L"Create");

	while (siv::System::Update())
	{
		if (!sceneManager.updateAndDraw())
			break;
	}
}
