#pragma once
#include <WinSock2.h>
#include <string>

namespace tcpframework {
	


	class TcpManager {
		WSADATA m_wsa_data;
		TcpManager() = default;
		static TcpManager* instance;
	public:
		
		static bool Init() {
			if (instance != nullptr)return false;
			//API初期化処理
			int error=WSAStartup(MAKEWORD(2, 0), &instance->m_wsa_data);
			if (error != 0)return false;
			return true;
		}

		static void End() {
			//API終了処理
			WSACleanup();
			delete instance;
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