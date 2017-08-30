#pragma once
#include <memory>
#include <string>

namespace tcpframework {

	class ByteArray {

		const size_t m_size;
		char* m_bytes;

	public:

		ByteArray(char const*const byte, size_t size):m_size(size){
			m_bytes = new char[size];
			for (size_t i = 0; i < size; i++) {
				m_bytes[i] = byte[i];
			}
		}

		ByteArray() :m_size(-1), m_bytes(nullptr){}

		ByteArray(const ByteArray&) = delete;

		ByteArray(ByteArray&& move) :m_size(move.m_size){
			m_bytes = move.m_bytes;
			move.m_bytes = nullptr;
		}

		~ByteArray() {
			if(m_bytes!=nullptr)
			delete[] m_bytes;
		}

		size_t Size()const noexcept { return m_size; }

		char const * const GetBytes()const noexcept { return m_bytes; }
	};

	class ClientSocket {
		class ClientSocket_impl;
		std::unique_ptr<ClientSocket_impl> impl;
	public:
		ClientSocket(unsigned short port,const std::string& serverIp);

		~ClientSocket();

		//ê⁄ë±Çë“ã@Ç∑ÇÈÅB
		bool Connect()const;

		int Send(const std::string&)const;
		ByteArray Receive()const;

		bool Close();
	};
}