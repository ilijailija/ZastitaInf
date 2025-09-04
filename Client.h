#pragma once

#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>

class Client
{
	SOCKET clientSocket;
	SOCKET acceptSocket;
public:
	Client();
	void ConnectToServer(int port);
	void Send(std::string message);
	void Recieve();
	SOCKET getSocket();
	void sendFileData(std::string fileName, long fileSize, int hashLenght, std::byte* hash, std::string encryptedMsg);
};
