#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <vector>
#include "MD5Alg.cpp"
using namespace std;

class Server
{
	SOCKET serverSocket;
	SOCKET acceptSocket;
public:
	Server();
	void BindSocket(int port);
	void Listen();
	void AcceptSocket();
	void Recieve();
	void Send(string message);
	vector<string> RecieveFileData();
};

