#include "ServerSocket.hpp"
#include "SendSocket.hpp"
#include <WinSock2.h>

namespace tcpframework {
	class ServerSocket::ServerSocket_impl {
		SOCKET m_sock;
		sockaddr_in m_addr;
		const int m_max_connect;
	public:
		ServerSocket_impl(u_short port, int max_connect)
			:m_sock(socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)),
			m_max_connect(max_connect)
		{
			m_addr.sin_family = AF_INET;
			m_addr.sin_port = htons(port);
			m_addr.sin_addr.S_un.S_addr = INADDR_ANY;
		}

		bool Bind() {
			return bind(m_sock, reinterpret_cast<sockaddr*>(&m_addr), sizeof(m_addr)) == 0;
		}

		bool Listen() {
			return listen(m_sock, m_max_connect) == 0;
		}

		std::unique_ptr<SendSocket> Accept() {
			sockaddr_in client;
			int len = sizeof(client);
			SOCKET socket = accept(m_sock, reinterpret_cast<sockaddr *>(&client), &len);
			if (socket == INVALID_SOCKET)
				return nullptr;
			return std::make_unique<SendSocket>(socket, client);
		}
	};

	ServerSocket::ServerSocket(unsigned short port, int max_connect)
		:impl(std::make_unique<ServerSocket_impl>(port,max_connect))
	{
	}

	ServerSocket::~ServerSocket()
	{
	}

	bool ServerSocket::Bind()
	{
		return impl->Bind();
	}

	bool ServerSocket::Listen()
	{
		return impl->Listen();
	}

	std::unique_ptr<SendSocket> ServerSocket::Accept()
	{
		return impl->Accept();
	}

}