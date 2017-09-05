#include "SendSocket.hpp"
#include <string>
#include <WinSock2.h>

namespace tcpframework {
	class SendSocket::SendSocket_impl {
		SOCKET2 m_sock;
		sockaddr_in m_addr;
		//受信したデータをひとつ分貯める
		ByteArray m_buf;
	public:
		SendSocket_impl(const SOCKET2& sock, const sockaddr_in& addr) :
		m_sock(sock), m_addr(addr){}

		int Send(const std::string str){
			return send(m_sock, str.c_str(), str.size(), 0);
		}

		bool Close() {
			return shutdown(m_sock, SD_BOTH) == 0 && closesocket(m_sock) == 0;
		}

		int Receive() {
			//受信バッファ
			static char recvbuf[RECVSIZE];
			//得たバイト数を記録する変数
			int givebyte;
			//データを受信
			givebyte = recv(m_sock, recvbuf, sizeof(recvbuf), 0);
			if (givebyte == SOCKET_ERROR) { return SOCKET_ERROR; }
			m_buf= ByteArray(recvbuf, givebyte);
			return givebyte;
		}

		ByteArray GetBuf()noexcept {
			return std::move(m_buf);
		}

	};

	SendSocket::SendSocket(const SOCKET2 & sock, const sockaddr_in & addr)
		:impl(std::make_unique<SendSocket_impl>(sock,addr))
	{
	}

	SendSocket::~SendSocket()
	{
	}

	int SendSocket::Receive()
	{
		return impl->Receive();
	}

	ByteArray SendSocket::GetBuf() noexcept
	{
		return impl->GetBuf();
	}

	bool SendSocket::Close()
	{
		return impl->Close();
	}

	int SendSocket::Send(const std::string & str)
	{
		return impl->Send(str);
	}

}