#include "Client.h"
Client::Client() {
	clientSocket = INVALID_SOCKET;
	clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (clientSocket == INVALID_SOCKET) {
		std::cout << "Error at socket(): " << WSAGetLastError() << std::endl;
		WSACleanup();
	}
	else {
		std::cout << "client socket is OK." << std::endl;
	}
}
void Client::ConnectToServer(int port) {
	sockaddr_in clientService;
	clientService.sin_family = AF_INET;
	InetPton(AF_INET, (L"127.0.0.1"), &clientService.sin_addr.s_addr);
	clientService.sin_port = htons(port);
	if (connect(clientSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR) {
		std::cout<<"Client::connect() - Failed to connect" << std::endl;
		WSACleanup();
	}
	else {
		std::cout << "Client::connect is ok!"<< std::endl;
		std::cout << "Client: can start sending and recieving data"<< std::endl;
	}
}
void Client::Send(std::string message) {
	const char* cMessage = message.c_str();
	int length = message.size();
	int byteCount = send(clientSocket, cMessage, length, 0);
	if (byteCount == SOCKET_ERROR) {
		printf("Server send error &ld.\n", WSAGetLastError());
	}
	else
		printf("Server: sent %ld bytes \n", byteCount);
}
void Client::Recieve() {
	char recieveBuffer[1000] = "";
	int byteCount = recv(acceptSocket, recieveBuffer, 1000, 0);
	if (byteCount < 0) {
		printf("Client:error %ld.\n", WSAGetLastError());
	}
	else
		printf("Received data: %s \n", recieveBuffer);
}
SOCKET Client::getSocket() {
	return clientSocket;
}

void Client::sendFileData(std::string fileName, long fileSize, int hashLenght, std::byte* hash, std::string encryptedMsg) {
	fileName += '\n';
	send(clientSocket, fileName.c_str(), fileName.size(), 0); // ime fajla (string)
	send(clientSocket, reinterpret_cast<const char*>(&fileSize), sizeof(fileSize), 0);//duzina fajla (long)
	send(clientSocket, reinterpret_cast<const char*>(&hashLenght), sizeof(hashLenght), 0);//duzina hash-a (int)
	send(clientSocket, reinterpret_cast<const char*>(hash), hashLenght, 0);// hash(byte[])
	send(clientSocket, reinterpret_cast<const char*>(&encryptedMsg), encryptedMsg.length(), 0);//poruka(string)
}