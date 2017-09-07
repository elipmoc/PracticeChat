#pragma once
#include <memory>
#include <string>
#include "def.hpp"
#include "ByteArray.hpp"

namespace tcpframework {
	class ClientSocket {
		SOCKET m_sock;
		std::unique_ptr<sockaddr_in> m_serverData;
		const unsigned short m_port;
		//受信したデータをひとつ分貯める
		ByteArray m_buf;
		//ソケット終了フラグ
		bool closeFlag = false;
	public:

		ClientSocket(unsigned short port,const std::string& serverIp);

		~ClientSocket();

		//接続を待機する。
		bool Connect()const;

		//データを送信する
		int Send(const std::string&)const;

		//データをBufに貯める
		//返り値はバイト数で
		//エラーなら-1が返る
		int Receive();

		//Bufを得る
		ByteArray GetBuf();

		//ソケットを終了する
		bool Close();
	};
}