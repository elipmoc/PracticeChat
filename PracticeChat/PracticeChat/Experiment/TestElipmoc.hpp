#pragma once
#include "../tcpframework/tcpframework.hpp"
#include <fstream>
namespace experiment {

	class TestElipmoc {
		std::unique_ptr<tcpframework::ClientSocket> client;
	public:

		void Init() {
			siv::Println(tcpframework::TcpManager::Init());
			client = std::make_unique<tcpframework::ClientSocket>(80, "yahoo.co.jp");
			siv::Println(client->Connect());
			client->Send(
				"GET  HTTP/1.0\r\n\r\n"
			);
			std::ofstream ofs("html.html");
			while (client->Receive() > 0) {
				auto bytes = client->GetBuf();
				std::string s(bytes.GetBytes(), bytes.Size());
			//	siv::Println(siv::CharacterSet::Widen(s));
				ofs << s;
			}
			ofs.close();
		}
		void Update() {
		/*	if (client->Receive()==-1)
				return;
			auto bytes = client->GetBuf();
			std::string s(bytes.GetBytes(),bytes.Size());
			siv::Println(siv::CharacterSet::Widen(s));
			siv::Println(L"adfaf");*/
		}
		void End() {
			client->Close();
			tcpframework::TcpManager::End(); 
		}
	};
}