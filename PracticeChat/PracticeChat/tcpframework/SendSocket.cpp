#include "SendSocket.hpp"
#include <string>
#include <queue>
#include <mutex>
#include <WinSock2.h>

namespace tcpframework {
	class SendSocket::SendSocket_impl {
		SOCKET m_sock;
		std::mutex mtx;
		sockaddr_in m_addr;
		//受信したデータをキューに貯める
		std::queue<ByteArray> m_buf_queue;
	public:
		SendSocket_impl(const SOCKET& sock, const sockaddr_in& addr) :
		m_sock(sock), m_addr(addr){}

		int Send(const std::string str){
			return send(m_sock, str.c_str(), str.size(), 0);
		}

		bool Close() {
			return shutdown(m_sock, SD_BOTH) == 0 && closesocket(m_sock) == 0;
		}

		int Receive(){
			//受信バッファ
			static char recvbuf[RECVSIZE];
			//得たバイト数を記録する変数
			int givebyte;
			//データを受信
			givebyte = recv(m_sock, recvbuf, sizeof(recvbuf), 0);
			if (givebyte == SOCKET_ERROR || givebyte == 0) { return givebyte; }

			//ロック
			std::lock_guard<std::mutex> lock(mtx);
			m_buf_queue.push(ByteArray(recvbuf, givebyte));
			return givebyte;
		}

		bool IsEmptyBuf()const{
			return m_buf_queue.empty();
		}

		ByteArray PopBuf(){
			//ロック
			std::lock_guard<std::mutex> lock(mtx);
			auto bytes= std::move(m_buf_queue.front());
			m_buf_queue.pop();
			return std::move(bytes);
		}

	};

	SendSocket::SendSocket(const SOCKET & sock, const sockaddr_in & addr)
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

	ByteArray SendSocket::PopBuf() 
	{
		return impl->PopBuf();
	}

	bool SendSocket::IsEmptyBuf() const 
	{
		return impl->IsEmptyBuf();
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