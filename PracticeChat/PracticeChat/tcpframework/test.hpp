#pragma once
#include <WinSock2.h>
#include <string>

namespace tcpframework {
	
	class TcpManager {
		WSADATA m_wsa_data;
	public:
		TcpManager() {}
		bool Init() {
			WSAStartup(MAKEWORD(2, 0), &m_wsa_data);
			return true;
		}
	};


	class Test {
		SOCKET sock;
	public:
		Test()
			:sock(socket(AF_INET,SOCK_STREAM, IPPROTO_TCP))
		{

		}
	};
}