#include "Server.h"

Server::Server(int PORT)
{
	TIME->printTime();

	WSADATA wsaData;

	ListenSocket = INVALID_SOCKET;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		printf("WSAStartup failed with error: %d\n", iResult);
		exit(0);
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	// Resolve the server address and port
	iResult = getaddrinfo(NULL, std::to_string(PORT).c_str(), &hints, &result);
	if (iResult != 0)
	{
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		exit(0);
	}

	// Create a SOCKET for connecting to server
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ListenSocket == INVALID_SOCKET)
	{
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		exit(0);
	}

	// Setup the TCP listening socket
	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR)
	{
		std::cout << "Bind failed with error: " << WSAGetLastError() << std::endl;
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		exit(0);
	}

	freeaddrinfo(result);

	//listen for incoming connection
	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR)
	{
		printf("listen failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		exit(0);
	}

	serverPtr = this;
}

bool Server::ListenForNewConnection()
{

	SOCKET ClientSocket = INVALID_SOCKET;
	ClientSocket = accept(ListenSocket, NULL, NULL);
	if (ClientSocket == INVALID_SOCKET)
	{
		printf("accept failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return false;
	}

	else // sucessfull connection
	{
		std::cout << "Client connected" << std::endl;
		Connections[ConnectionCounter] = ClientSocket;

		// authentify user
		// + loads into memory and sends the client user data
		if (!Authentify(ConnectionCounter)) {
			return false;
		}

		connectionThreads[ConnectionCounter] = thread(ClientHandler, ConnectionCounter);

		ConnectionCounter++;
		return true;
	}
}

bool Server::SendInt(int id, int value)
{
	int returnCheck = send(Connections[id], (char*)&value, sizeof(int), NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Server::GetInt(int id, int& value)
{
	int returnCheck = recv(Connections[id], (char*)&value, sizeof(int), NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Server::SendBool(int id, bool value)
{
	int returnCheck = send(Connections[id], (char*)&value, sizeof(bool), NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Server::GetBool(int id, bool& value)
{
	int returnCheck = recv(Connections[id], (char*)&value, sizeof(bool), NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Server::SendString(int id, string& value)
{
	int bufferLength = value.size();
	if (!SendInt(id, bufferLength))
		return false;

	int returnCheck = send(Connections[id], value.c_str(), bufferLength, NULL);
	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Server::GetString(int id, string& value)
{
	int bufferLength = 0;
	if (!GetInt(id, bufferLength))
		return false;

	char* buffer = new char[bufferLength + 1]; // +1 tro allow for terminating '/0'

	int returnCheck = recv(Connections[id], buffer, bufferLength, NULL);
	buffer[bufferLength] = '\0';
	value = buffer;
	delete[] buffer;

	if (returnCheck == SOCKET_ERROR)
		return false;

	return true;
}

bool Server::ProcessString(int index, string value)
{
	if (!GetString(index, value))
		return false;

	vector<string> unparsedStringVector = PARSER->unparseString(value, '$');

	FunctionCode functionCall = (FunctionCode)atoi(unparsedStringVector[0].c_str());

	Protocol protocol(functionCall, value);

	string sendString;
	vector<string> sendVectString;

	switch (functionCall)
	{
	case(FunctionCode::SendClientAllUserData):
		sendVectString.push_back(this->userList[index]->getUserFullName());
		PARSER->protocoliseString(1, sendVectString);
		sendString = PARSER->parseString(sendVectString, '$');

		if (!SendString(index, sendString))
			return false;
		break;

	case(FunctionCode::ChangeUserPassword):
	{
		ChangeUserPassword(index, unparsedStringVector);
		break;
	}
	case(FunctionCode::InsertNewUser):
	{
		InsertNewUser(index, unparsedStringVector);
		break;
	}
	case(FunctionCode::SendAllOnlineClients):
	{
		SendAllOnlineClients(index);
		break;
	}
	default:
	{
		cout << "******* Invalid Protocol Function Call *******" << endl;
		return false;
		break;
	}
	}

	return true;
}

void Server::LoadUserInfo(int index, string _firstName)
{
	int _ID = SQL_MANAGER->getUserID(_firstName);
	int _Role = SQL_MANAGER->getUserRole(_firstName);

	IUSer* tempUser;

	switch (_Role)
	{
	case 1: {
		tempUser = FactoryUser::createUser();
		break;
	}
	case 2: {
		tempUser = FactoryUser::createUserAdmin();
		break;
	}
	default:
		tempUser = FactoryUser::createUser();
	}

	tempUser->setConnectionData(SQL_MANAGER->getUserLastName(_ID),
		_firstName,
		SQL_MANAGER->getUserJoinedDate(_ID),
		_ID,
		_Role);

	userList.push_back(tempUser);
}

bool Server::SendUserInfo(int index)
{
	vector<string> sendMessageVector = {
		to_string(userList[index]->getUserID()),
		userList[index]->getUserLastName(),
		userList[index]->getUserFirstName(),
		userList[index]->getUserJoinDate(),
		to_string(userList[index]->getUserRole())
	};

	int userRole = userList[index]->getUserRole();
	// Roluri diferite aici

	string parsedString = PARSER->parseString(PARSER->protocoliseString((int)FunctionCode::SendClientAllUserData, sendMessageVector), '$');

	Protocol protocol((FunctionCode)1, parsedString);

	if (!SendString(index, parsedString)) {
		cout << "Sending user " + to_string(index) + " data failed." << endl;
		return false;
	}

	return true;
}

void Server::ChangeUserPassword(int index, vector<string> vStr)
{
	//userID, newPassword
	SQL_MANAGER->setUserPassword(userList[index]->getUserID(), vStr[1]);
}

void Server::InsertNewUser(int index, vector<string> vStr)
{
	//userRole, LastName, FirstName, Password
	string buffer;

	{
		buffer += "(";
		buffer += vStr[1];
		buffer += ", '";
		buffer += vStr[2];
		buffer += "', '";
		buffer += vStr[3];
		buffer += "', '";
		buffer += HASH->getPasswordHash(vStr[4]);
	}

	switch (atoi(vStr[1].c_str()))
	{
	case(1):
	{
		SQL_MANAGER->insertNewUser(buffer);
		break;
	}
	case(2):
	{
		SQL_MANAGER->insertNonUser(buffer);
		break;
	}
	default:
	{
		cout << "Invalid Role" << endl;
		return;
	}
	}
}

void Server::SendAllOnlineClients(int index)
{
	vector<string> unparsedVect = { to_string(9), to_string(userList.size()) };
	for (int i = 0; i < userList.size(); i++)
	{
		unparsedVect.push_back(userList[i]->getUserFullName());
		unparsedVect.push_back(to_string(userList[i]->getUserID()));
		unparsedVect.push_back(to_string(userList[i]->getUserRole()));
	}
	string sendString = PARSER->parseString(unparsedVect, '$');
	SendString(index, sendString);
}

bool Server::CloseConnection(int index)
{
	userList.erase(userList.begin() + index);
	if (closesocket(Connections[index]) == SOCKET_ERROR)
	{
		cout << "Failed closing Error: " << WSAGetLastError() << endl;
		return false;
	}
	return true;
}

bool Server::Authentify(int index)
{
	string usernameString;
	string userpassString;
	do
	{
		if (!GetString(index, usernameString))
		{
			SendBool(index, false);
			return false;
		}
		SendBool(index, true);

		if (!GetString(index, userpassString))
		{
			SendBool(index, false);
			return false;
		}
		SendBool(index, true);

		if (!SQL_MANAGER->authentifyUser(usernameString, userpassString))
			SendBool(index, false);
		else {
			SendBool(index, true);
			break;
		}
	} while (true);

	cout << "Connection succesful." << endl;

	//Loads into memory
	LoadUserInfo(ConnectionCounter, usernameString);
	SendUserInfo(ConnectionCounter);
}

void Server::ClientHandler(int index)
{
	string receiveString;
	while(true)
	{
		if (!serverPtr->ProcessString(index, receiveString))
			break;
	}

	cout << "Lost contact with client: id = " << index << endl;

	serverPtr->CloseConnection(index);
}

