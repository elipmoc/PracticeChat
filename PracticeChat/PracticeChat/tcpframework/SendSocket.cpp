#include "SendSocket.hpp"
#include <string>
#include <WinSock2.h>

namespace tcpframework {
	class SendSocket::SendSocket_impl {
		SOCKET m_sock;
		sockaddr_in m_addr;
	public:
		SendSocket_impl(const SOCKET& sock, const sockaddr_in& addr) :
		m_sock(sock), m_addr(addr){}

		int Send(const std::string str){
			return send(m_sock, str.c_str(), str.size(), 0);
		}
	};

	SendSocket::SendSocket(const SOCKET & sock, const sockaddr_in & addr)
		:impl(std::make_unique<SendSocket_impl>(sock,addr))
	{
	}

	SendSocket::~SendSocket()
	{
	}

	int SendSocket::Send(const std::string & str)
	{
		return impl->Send(str);
	}

}