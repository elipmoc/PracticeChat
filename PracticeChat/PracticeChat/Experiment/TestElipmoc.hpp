#pragma once
#include "../tcpframework/test.hpp"
namespace experiment {

	class TestElipmoc {
	public:
		void Init() {
			siv::Println(tcpframework::TcpManager::Init());
			tcpframework::ServerSocket serverSocket(19132, 5);
			siv::Println(serverSocket.Bind());
			siv::Println(serverSocket.Listen());
			auto send = serverSocket.Accept();
			send->Send("Ç¢Ç¢ÇÊÇ±Ç¢ÇÊÅIÅI");
		}
		void Update() {}
		void End() { tcpframework::TcpManager::End(); }
	};
}