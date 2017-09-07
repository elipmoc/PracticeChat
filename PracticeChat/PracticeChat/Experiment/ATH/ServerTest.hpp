#pragma once
#include "../../tcpframework/tcpframework.hpp"
#include <vector>
#include <mutex>

#pragma once

namespace experiment {
	namespace ATH {
		template<class T>
		using u_ptr = std::unique_ptr<T>;
		using tcpframework::ServerSocket;
		using tcpframework::SendSocket;
		using tcpframework::ClientSocket;
		using tcpframework::ByteArray;

		class ServerTest
		{
			u_ptr<ServerSocket> server;
			std::mutex mtx;
			std::vector<u_ptr<SendSocket>> send;
		public:
			ServerTest();
			~ServerTest();

			void Init() {
				siv::Println(tcpframework::TcpManager::Init());
				server = std::make_unique<tcpframework::ServerSocket>(19132, 5);
				siv::Println(server->Bind());
				siv::Println(server->Listen());
				server->AcceptAsync([&send = send, &mtx = mtx](auto sendsock) mutable
				{
					sendsock->ReceiveAsync([sendsock = sendsock.get()](ByteArray&& bytes, int byteSize)mutable
					{
						if (byteSize == -1) {
							sendsock->Close();
							return false;
						}
						std::string s(bytes.GetBytes(), bytes.Size());
						siv::Println(siv::CharacterSet::Widen(s));
						return true;
					});

					std::lock_guard<std::mutex> lock(mtx);
					send.push_back(std::move(sendsock));
					return true;
				});
			}

			void Update() {
				std::lock_guard<std::mutex> lock(mtx);
				auto itr =
					std::remove_if(send.begin(), send.end(), [](const u_ptr<SendSocket>& sendSocket) {
					return sendSocket->IsClose();
				});
				send.erase(itr, send.end());
			}

			void SendMessage(const std::string sendMessage) {
				std::lock_guard<std::mutex> lock(mtx);
				// std::vector<u_ptr<SendSocket>> send;
				for(auto& sendsock : send)
				{
					sendsock->Send(sendMessage);
				}
			}
		};
	}
}

