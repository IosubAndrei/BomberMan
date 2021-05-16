#define _CRT_SECURE_NO_WARNINS
#include <iostream>
#include <WS2tcpip.h>

#pragma comment (lib, "ws2_32.lib")

using namespace std;

void main()
{
	//initializez winsock
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);

	int wsok = WSAStartup(ver, &wsData);
	if (wsok != 0)
	{
		cerr << "Nu se poate initializa winsock! Quitting!" << endl;
	}

	//create a socket
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET)
	{
		cerr << "Nu se poate creea un socket! Quitting!" << endl;
		return;
	}

	//bind the sochet to an ip address and port

	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000); //host to networks short
	hint.sin_addr.S_un.S_addr = INADDR_ANY;

	bind(listening, (sockaddr*)&hint, sizeof(hint));

	//tell windows sockets that the socket is for listening

	listen(listening, SOMAXCONN);

	//wait for a connection
	sockaddr_in client;
	int clientSize = sizeof(client);

	SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

	char host[NI_MAXHOST]; //client's remote name
	char service[NI_MAXHOST]; //service(i.e. port) the client is connect on

	ZeroMemory(host, NI_MAXHOST); //la fel ca memset(host,0,NI_MAXHOST);
	ZeroMemory(service, NI_MAXHOST);



	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
	{
		cout << host << "connnected on port " << service << endl;

	}
	else
	{
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		cout << host << "connected on port" << ntohs(client.sin_port) << endl;
	}

	//close listening socket 

	closesocket(listening); //ar trebui sa ramana deschisa conexiunea

	//while loop: accept and echo message back to client
	char buf[4096];

	while (true)
	{
		ZeroMemory(buf, 4096);
		//wait for client to send data
		int bytesReceived = recv(clientSocket, buf, 4096, 0);
		if (bytesReceived == SOCKET_ERROR)
		{
			cerr << "Error in recv(). Quitting." << endl;
			break;
		}
		if (bytesReceived == 0)
		{
			cout << "Client disconnected" << endl;
			break;
		}
		//echo message back to client
		send(clientSocket, buf, bytesReceived + 1, 0);

	}

	//close the socket 
	closesocket(clientSocket);

	//cleanup winsock
	WSACleanup();


}