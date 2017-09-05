#pragma once
#include <memory>

//くそのwinsockで定義されている型を前方宣言
typedef unsigned int UINT_PTR2;
typedef UINT_PTR2 SOCKET2;
struct sockaddr_in;
namespace tcpframework {
	//送信用ソケットクラス
	class SendSocket {
		class SendSocket_impl;
		std::unique_ptr<SendSocket_impl> impl;

	public:
		//接続先のソケットとその接続先の情報を渡す
		SendSocket(const SOCKET2& sock, const sockaddr_in& addr);
		~SendSocket();

		bool Close();

		//データを送信する（返り値は送信したバイト数。 -1でエラー）
		int Send(const std::string& str);
	};
}