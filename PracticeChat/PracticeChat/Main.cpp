#include "chat\header\LoginScene.hpp"
#include "chat\header\RoomScene.hpp"
#include "chat\header\ServerScene.hpp"
#include "chat\header\CreateScene.hpp"
#include "Experiment\TestElipmoc.hpp"
#include "Experiment\Test_A_TO_HA.hpp"
#include "Experiment\Test���c.hpp"

void Main()
{
	chat::MySceneManager sceneManager;

	sceneManager.add<LoginScene>(L"Login");
	sceneManager.add<ServerScene>(L"Server");
	sceneManager.add<RoomScene>(L"Room");
	sceneManager.add<CreateScene>(L"Create");
	experiment::TestElipmoc e;
	experiment::Test_A_TO_HA a;
	experiment::TestStar s;
	e.Init();
	a.Init();
	s.Init();
	
	
	while (siv::System::Update())
	{
		e.Update();
		a.Update();
		s.Update();
		if (!sceneManager.updateAndDraw())
			break;
	}
	 e.End();
	a.End();
	s.End();
}
