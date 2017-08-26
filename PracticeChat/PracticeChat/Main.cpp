#include "chat\header\RoomScene.h"

void Main()
{
	chat::MySceneManager sceneManager;

	sceneManager.add<RoomScene>(L"Room");

	while (siv::System::Update())
	{
		if (!sceneManager.updateAndDraw())
			break;
	}
}
