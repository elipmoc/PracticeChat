#pragma once
#include "../tcpframework/tcpframework.hpp"
#include <fstream>
#include <future>
namespace experiment {

	class TestElipmoc {
		std::unique_ptr<tcpframework::ServerSocket> server;
		std::unique_ptr<tcpframework::SendSocket> send;
		std::future<void> f;
	public:

		void Init() {
			siv::Println(tcpframework::TcpManager::Init());
			server = std::make_unique<tcpframework::ServerSocket>(19132, 5);
			siv::Println(server->Bind());
			siv::Println(server->Listen());
			send=server->Accept();
			send->Send("‚¤‚í‚í‚í‚í‚í‚í‚—‚—‚—‚—‚—");
			f=std::async(std::launch::async, [send = &send]() {
				while(send->get()->Receive()!=-1);
			});
		}
		void Update() {
			
			
			if (send->IsEmptyBuf())
				return;
			auto bytes = send->PopBuf();
			std::string s(bytes.GetBytes(),bytes.Size());
			siv::Println(siv::CharacterSet::Widen(s));
		}
		void End() {
			server->Close();
			send->Close();
			tcpframework::TcpManager::End(); 
		}
	};
}