#pragma once
#include <memory>
#include <thread>
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
		const SOCKET m_sock;
		//ソケットを終了したかどうか
		bool closeFlag = false;
	public:
		//接続先のソケットを渡す
		SendSocket(const SOCKET& sock) :m_sock(sock){};
		~SendSocket();

		//データを受け取る
		int Receive(ByteArray&&);

		//Receiveの非同期版
		template<class GetResultFunc>
		void ReceiveAsync(GetResultFunc func) {
			std::thread thr([&func, this]() {
				ByteArray bytes;
				while (true) {
					int byteSize = this->Receive(std::move(bytes));
					if (func(std::move(bytes), byteSize) == false)return;
				}
			});
			thr.detach();
		}

		//ソケット終了処理
		bool Close();

		bool IsClose() const noexcept { return closeFlag; }

		//データを送信する（返り値は送信したバイト数。 -1でエラー）
		int Send(const std::string& str);
	};
}