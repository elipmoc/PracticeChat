#include "chat\header\RoomScene.h"
#include "chat\header\LoginScene.h"

void Main()
{
	chat::MySceneManager sceneManager;

	sceneManager.add<RoomScene>(L"Room");
	sceneManager.add<LoginScene>(L"Login");

	while (siv::System::Update())
	{
		if (!sceneManager.updateAndDraw())
			break;
	}
}
