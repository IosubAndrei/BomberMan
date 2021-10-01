#undef UNICODE
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <iostream>
#include <thread>

#include "SQLManager.h"
#include "Query.h"
#include "Server.h"

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")

#define DEFAULT_PORT 42069
#define DEFAULT_BUFLEN 512
#define MAX_CLIENTS 100

int main()
{
	srand(time(NULL));

	Server server(DEFAULT_PORT);

	cout << "Server up and running." << endl;

	for (int i = 0; i < MAX_CLIENTS; i++)
	{
		server.ListenForNewConnection();
	}

	//string userString = "('Iosub','Andrei','iosub.andrei@mta.ro','parolaIosub',GETDATE(), 1)";
	//SQL_MANAGER->insertNewUser(userString);

	//SQL_MANAGER->setUserPassword(1, "mihail_popa_2014");
	//int seed = HASH->extractSeed(SQL_MANAGER->getPassword(1));
	//cout << HASH->getPasswordHash("andrei");
	//cout << SQL_MANAGER->getAllUserData(1);

	//if (SQL_MANAGER->authentifyUser("Mihai", "mihail_popa_2014"))
	//	cout << " Merge " << endl;
	//else
	//	cout << " Nu merge " << endl;

	//cout << SQL_MANAGER->getAllUserNames();

	system("pause");

	return 0;
}