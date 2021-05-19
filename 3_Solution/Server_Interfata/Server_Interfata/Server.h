#pragma once
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <vector>
#include <string>
#include <thread>

#include "SQLManager.h"
#include "Parser.h"
#include "IUser.h"
#include "FactoryUser.h"
#include "Admin.h"
#include "FunctionCode.h"
#include "TrustedTime.h"
#include "Protocol.h"

using namespace std;

#define SQL_MANAGER SQLManager::getInstance()
#define TIME TrustedTime::getInstance()

class Server
{
public:
	Server(int PORT);
	bool ListenForNewConnection();

	vector<IUSer*> userList = {};

private:
	SOCKET Connections[100];
	thread connectionThreads[100];

	addrinfo* result;
	addrinfo hints;
	SOCKET ListenSocket;
	int iResult;
	int ConnectionCounter = 0;

	//User-level functions
	bool Authentify(int id);
	void LoadUserInfo(int index, string uEmail);
	bool SendUserInfo(int index);

	void ChangeUserPassword(int index, vector<string> vStr);
	void InsertNewUser(int index, vector<string> vStr);
	void SendAllOnlineClients(int index);

	//Server-level functions
	bool GetInt(int id, int& value);
	bool SendInt(int id, int value);
	bool SendBool(int id, bool value);
	bool GetBool(int id, bool& value);
	bool SendString(int id, string& value);
	bool GetString(int id, string& value);
	bool CloseConnection(int index);

	bool ProcessString(int index, string value);

	static void ClientHandler(int index);
};

static Server* serverPtr;
