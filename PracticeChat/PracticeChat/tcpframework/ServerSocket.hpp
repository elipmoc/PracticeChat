#pragma once
#include <memory>
namespace tcpframework {

	class SendSocket;

	//サーバで使うソケットクラス
	class ServerSocket {
		class ServerSocket_impl;
		std::unique_ptr<ServerSocket_impl> impl;


	public:
		ServerSocket(unsigned short port, int max_connect);

		~ServerSocket();

		bool Bind();

		bool Listen();

		std::unique_ptr<SendSocket> Accept();
	};

}