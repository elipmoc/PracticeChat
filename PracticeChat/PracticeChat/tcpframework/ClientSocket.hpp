#pragma once
#include <memory>
#include <string>

namespace tcpframework {
	class ClientSocket {
		class ClientSocket_impl;
		std::unique_ptr<ClientSocket_impl> impl;
	public:
		ClientSocket(unsigned short port,const std::string& serverIp);

		~ClientSocket();

		//Ú‘±‚ğ‘Ò‹@‚·‚éB
		bool Connect()const;

		int Send(const std::string&)const;
	};
}