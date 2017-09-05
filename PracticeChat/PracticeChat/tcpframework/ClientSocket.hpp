#pragma once
#include <memory>
#include <string>
#include "ByteArray.hpp"

namespace tcpframework {
	class ClientSocket {
		class ClientSocket_impl;
		std::unique_ptr<ClientSocket_impl> impl;
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