#pragma once
#include "../tcpframework/tcpframework.hpp"
#include <vector>
#include <mutex>
#define SERVER
namespace experiment {
	template<class T>
	using u_ptr = std::unique_ptr<T>;
	using tcpframework::ServerSocket;
	using tcpframework::SendSocket;
	using tcpframework::ClientSocket;
	using tcpframework::ByteArray;

	class TestElipmoc {
		u_ptr<ServerSocket> server;
		u_ptr<ClientSocket> client;
		std::mutex mtx;
		std::vector<u_ptr<SendSocket>> send;
	public:
		void Init() {
			siv::Println(tcpframework::TcpManager::Init());
#ifdef SERVER
			server = std::make_unique<tcpframework::ServerSocket>(19132, 5);
			siv::Println(server->Bind());
			siv::Println(server->Listen());
			server->AcceptAsync([&send=send,&mtx=mtx](auto sendsock) mutable
			{
				sendsock->Send("��������킗��������");
				sendsock->ReceiveAsync([sendsock=sendsock.get()](ByteArray&& bytes, int byteSize)mutable
				{
					if (byteSize == -1) {
						sendsock->Close();
						return false; }
					std::string s(bytes.GetBytes(), bytes.Size());
					siv::Println(siv::CharacterSet::Widen(s));
					return true;
				});

				std::lock_guard<std::mutex> lock(mtx);
				send.push_back(std::move(sendsock));
				return true;
			});
#elif defined CLIENT
			client = std::make_unique<ClientSocket>(19132, "localhost");
			client->ConnectAsync([&client = client]() {
				client->Send("��������남���I"); 
				client->ReceiveAsync([](ByteArray&& bytes, int byteSize)mutable
				{
					if (byteSize == -1) {
						return false;
					}
					std::string s(bytes.GetBytes(), bytes.Size());
					siv::Println(siv::CharacterSet::Widen(s));
					return true;
				});

			});
#endif
		}
		void Update() {
#ifdef SERVER

			std::lock_guard<std::mutex> lock(mtx);
			auto itr=
				std::remove_if(send.begin(), send.end(), [](const u_ptr<SendSocket>& sendSocket) {
				return sendSocket->IsClose();
			});
			send.erase(itr, send.end());
			// siv::Println(send.size());
#elif defined CLIENT
#endif
		}
		void End() {
			tcpframework::TcpManager::End(); 
		}
	};
}