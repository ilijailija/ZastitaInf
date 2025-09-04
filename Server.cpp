#include "Server.h"
Server::Server() {
	serverSocket = INVALID_SOCKET;

	serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serverSocket == INVALID_SOCKET) {
		cout << "Error at socket(): " << WSAGetLastError() << endl;
		WSACleanup();
	}
	else {
		cout << "server socket is OK." << endl;
	}
}
void Server::BindSocket(int port) {
	sockaddr_in service;
	service.sin_family = AF_INET;
	InetPton(AF_INET, (L"127.0.0.1"), &service.sin_addr.s_addr);
	service.sin_port = htons(port);
	if (::bind(serverSocket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR) {
		cout << "bind() failed: " << WSAGetLastError() << endl;
		closesocket(serverSocket);
		WSACleanup();
	}
	else {
		cout << "bind() is ok!" << endl;
	}
}
void Server::Listen() {
	if (listen(serverSocket, 1) == SOCKET_ERROR)
		cout << "listen(): Error listening on socket" << WSAGetLastError() << endl;
	else
		cout << "listen() is OK, waiting for connections" << endl;
}
void Server::AcceptSocket() {
	acceptSocket = INVALID_SOCKET;
	acceptSocket = accept(serverSocket, NULL, NULL);
	if (acceptSocket == INVALID_SOCKET) {
		cout << "accept failed: " << WSAGetLastError() << endl;
		WSACleanup();
	}
	else {
		cout << "Socked accepted!" << endl;
	}
}
void Server::Recieve() {
	char recieveBuffer[1000] = "";
	int byteCount = recv(acceptSocket, recieveBuffer, 1000, 0);
	if (byteCount < 0) {
		printf("Client:error %ld.\n", WSAGetLastError());
	}
	else
		printf("Received data: %s \n", recieveBuffer);
}
void Server::Send(string message) {
	const char* cMessage = message.c_str();
	int length = message.size();
	int byteCount = send(serverSocket, cMessage, length, 0);
	if (byteCount == SOCKET_ERROR) {
		printf("Server send error &ld.\n", WSAGetLastError());
	}
	else
		printf("Server: sent %ld bytes \n", byteCount);
}
vector<string> Server::RecieveFileData() {
	vector<string> err;
	//1. fileName (string)
	string fileName;
	char ch;
	while (true) {
		recv(acceptSocket, &ch, 1, 0);
		if (ch == '\n')
			break;
		fileName += ch;
	}
	//2. fileSize (long)
	long fileSize = 0;
	recv(acceptSocket, reinterpret_cast<char*>(&fileSize), sizeof(long), 0);
	//3. hashLength (int)
	int hashLength = 0;
	recv(acceptSocket, reinterpret_cast<char*>(&hashLength), sizeof(int), 0);
	//4. hash(byte)
	vector<std::byte> recievedHash(hashLength);
	recv(acceptSocket, reinterpret_cast<char*>(recievedHash.data()), hashLength, 0);
	//5. encrypted message
	vector<char> encryptedBuffer(fileSize);
	int totalRecieved = 0;
	while (totalRecieved < fileSize) {
		int received = recv(acceptSocket, encryptedBuffer.data() + totalRecieved, fileSize - totalRecieved, 0);
		if (received <= 0) {
			printf("Error while receiving encrypted data. Error: %d\n", WSAGetLastError());
			return err;
		}
		totalRecieved += received;
	}
	string encryptedMsg(encryptedBuffer.begin(), encryptedBuffer.end());
	std::string computedHash = GetMD5String(encryptedMsg);

	bool hashOK = true;
	for (int i = 0; i < hashLength; i++) {
		if (std::byte(computedHash[i]) != recievedHash[i]) {
			hashOK = false;
			break;
		}
	}

	if (!hashOK) {
		cout << "Hashes are different!" << endl;
		return err;
	}
	vector<string> returnValue;
	returnValue.push_back(fileName);
	returnValue.push_back(encryptedMsg);
	return returnValue;
}