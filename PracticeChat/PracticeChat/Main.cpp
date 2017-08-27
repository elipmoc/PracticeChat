#include "tcpframework\test.hpp"

void Main()
{

	const siv::Font font(30);

	siv::Println(tcpframework::TcpManager::Init());
	tcpframework::ServerSocket serverSocket(19132,5);
	siv::Println(serverSocket.Bind());
	siv::Println(serverSocket.Listen());
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
