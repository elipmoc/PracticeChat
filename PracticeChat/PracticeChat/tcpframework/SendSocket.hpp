#pragma once
#include <memory>
#include "ByteArray.hpp"

//くそのwinsockで定義されている型を前方宣言
#ifdef	_WIN64
	typedef unsigned __int64 UINT_PTR;
#elif defined _WIN32
	typedef unsigned int UINT_PTR;
#endif 

	typedef UINT_PTR SOCKET;
	struct sockaddr_in;
namespace tcpframework {

	//送信用ソケットクラス
	class SendSocket {
		class SendSocket_impl;
		std::unique_ptr<SendSocket_impl> impl;

	public:
		//接続先のソケットとその接続先の情報を渡す
		SendSocket(const SOCKET& sock, const sockaddr_in& addr);
		~SendSocket();

		//データを受け取ってbufに貯める
		int Receive();

		//bufを得る
		ByteArray GetBuf()noexcept;

		//ソケット終了処理
		bool Close();

		//データを送信する（返り値は送信したバイト数。 -1でエラー）
		int Send(const std::string& str);
	};
}