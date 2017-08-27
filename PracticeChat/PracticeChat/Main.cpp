#include "chat\header\LoginScene.h"
#include "chat\header\RoomScene.h"
#include "chat\header\ServerScene.h"


void Main()
{
	chat::MySceneManager sceneManager;

	sceneManager.add<LoginScene>(L"Login");
	sceneManager.add<ServerScene>(L"Server");
	sceneManager.add<RoomScene>(L"Room");

	while (siv::System::Update())
	{
		if (!sceneManager.updateAndDraw())
			break;
	}
}
