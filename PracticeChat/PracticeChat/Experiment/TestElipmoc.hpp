#pragma once
#include "../tcpframework/tcpframework.hpp"
namespace experiment {

	class TestElipmoc {
		std::unique_ptr<tcpframework::ClientSocket> client;
	public:

		void Init() {
			siv::Println(tcpframework::TcpManager::Init());
			client = std::make_unique<tcpframework::ClientSocket>(19132, "localhost");
			siv::Println(client->Connect());
			client->Send("‚ ‚í‚ ‚ ‚ ‚ ‚ I");
			
		}
		void Update() {
			auto&& bytes=client->Receive();
			if (bytes.Size() == 0 || bytes.Size() == -1)
				return;
			std::string s(bytes.GetBytes(),bytes.Size());
			siv::Println(siv::CharacterSet::Widen(s));
		}
		void End() {
			client->Close();
			tcpframework::TcpManager::End(); 
		}
	};
}