#include "tcpframework\test.hpp"

void Main()
{

	const siv::Font font(30);

	tcpframework::TcpManager::Init();
	tcpframework::TcpManager::End();
	while (siv::System::Update())
	{
		font(L"ようこそ、真のGithub の世界へ！").draw();
		siv::Circle(siv::Mouse::Pos(), 100).draw({ 127, 127, 127, 127 });
		siv::Circle(siv::Mouse::Pos(), 70).draw({ 255, 255, 0, 127 });
		siv::Circle(siv::Mouse::Pos(), 50).draw({ 255, 0, 0, 127 });
		siv::Circle(siv::Mouse::Pos(), 20).draw({ 0, 127, 0, 127 });
		siv::Circle(siv::Mouse::Pos(), 10).draw({ 0, 0, 127, 127 });
	}
}
