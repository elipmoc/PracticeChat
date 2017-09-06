#pragma once
#include "../tcpframework/tcpframework.hpp"
namespace experiment {

	class TestElipmoc {
		std::unique_ptr<tcpframework::ServerSocket> server;
		std::unique_ptr<tcpframework::SendSocket> send;
	public:

		void Init() {
			siv::Println(tcpframework::TcpManager::Init());
			server = std::make_unique<tcpframework::ServerSocket>(19132, 5);
			siv::Println(server->Bind());
			siv::Println(server->Listen());
			send=server->Accept();
			send->Send("‚¤‚í‚í‚í‚í‚í‚í‚—‚—‚—‚—‚—");
			send->ReceiveAsync([](tcpframework::ByteArray&& bytes ,int byteSize) {
				if (byteSize == -1)return false;
				std::string s(bytes.GetBytes(), bytes.Size());
				siv::Println(siv::CharacterSet::Widen(s));
				return true;
			});
		}
		void Update() {
			

		}
		void End() {
			server->Close();
			send->Close();
			tcpframework::TcpManager::End(); 
		}
	};
}