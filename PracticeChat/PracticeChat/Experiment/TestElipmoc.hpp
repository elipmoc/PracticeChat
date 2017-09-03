#pragma once
#include "../tcpframework/tcpframework.hpp"
namespace experiment {

	class TestElipmoc {
		std::unique_ptr<tcpframework::ServerSocket> server;
		std::unique_ptr<tcpframework::SendSocket> send;
	public:

		void Init() {
			siv::Println(tcpframework::TcpManager::Init());
			server = std::make_unique<tcpframework::ServerSocket>(19132,5);
			siv::Println(server->Bind());
			siv::Println(server->Listen());
			send=server->Accept();
			send->Send("‚ ‚í‚ ‚ ‚ ‚ ‚ I");
			
		}
		void Update() {
			if (send->Receive()==-1)
				return;
			auto bytes = send->GetBuf();
			std::string s(bytes.GetBytes(),bytes.Size());
			siv::Println(siv::CharacterSet::Widen(s));
		}
		void End() {
			send->Close();
			server->Close();
			tcpframework::TcpManager::End(); 
		}
	};
}