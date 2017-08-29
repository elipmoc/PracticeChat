#pragma once
#include <memory>
namespace tcpframework {

	class SendSocket;

	//サーバでクライアントの待機に使うソケットクラス
	class ServerSocket {
		class ServerSocket_impl;
		std::unique_ptr<ServerSocket_impl> impl;


	public:
		ServerSocket(unsigned short port, int max_connect);

		~ServerSocket();

		//ソケットにポート、アドレスファミリー、サーバーのIPを紐づけ
		bool Bind();

		//ソケットの接続待機準備をする
		bool Listen();

		//接続を待機する。接続されたらその接続先のソケットを返す
		std::unique_ptr<SendSocket> Accept();
	};

}