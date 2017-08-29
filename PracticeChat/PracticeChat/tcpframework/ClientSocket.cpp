#include "ClientSocket.hpp"
#include <WinSock2.h>
#include <ws2tcpip.h>


namespace tcpframework {
	class ClientSocket::ClientSocket_impl {
		SOCKET m_sock;
		sockaddr_in m_serverData;
		const u_short m_port;

		//ホスト名をバイナリipに変換する
		static IN_ADDR serverNameToIp(const std::string& serverName) {
			in_addr hoge;
			//ip文字列をipネットワークバイトオーダーに変換する
			if(inet_pton(AF_INET,serverName.c_str(),&hoge)!=1){
				struct addrinfo hints, *res;
				int err;
				memset(&hints, 0, sizeof(hints));
				hints.ai_socktype = SOCK_STREAM;
				hints.ai_family = AF_INET;
				//ホスト名の時、ホスト名からhostent構造体取得
				if ((err = getaddrinfo(serverName.c_str(),nullptr,&hints,&res)))
					throw std::string("ホスト名をIPに変換失敗");

				hoge.S_un = ((struct sockaddr_in *)(res->ai_addr))->sin_addr.S_un;
				return hoge;
				freeaddrinfo(res);					
			}
			return hoge;
		}
	public:
		ClientSocket_impl(u_short port,const std::string& serverName)
			:
			m_port(port),
			m_sock(socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))
		{

			//接続先サーバーの設定

			//アドレスファミリ設定
			m_serverData.sin_family = AF_INET;
			//サーバーipの設定
			m_serverData.sin_addr.s_addr = serverNameToIp(serverName).S_un.S_addr;
			m_serverData.sin_port = htons(port);//ポート番号をビッグエンディアンに変換
		
		}

		bool Connect() {
			//つながるまでループ
			while (connect(m_sock, (LPSOCKADDR)&m_serverData, sizeof(m_serverData)) == SOCKET_ERROR)
			{
			}
			std::string str("aaa");
			send(m_sock,str.c_str(), str.size(), 0);
			return true;
		}

	};

	ClientSocket::ClientSocket(unsigned short port, const std::string & serverIp)
		:impl(std::make_unique<ClientSocket_impl>(port,serverIp))
	{
	}

	ClientSocket::~ClientSocket()
	{
	}

	bool ClientSocket::Connect()
	{
		return impl->Connect();
	}

}