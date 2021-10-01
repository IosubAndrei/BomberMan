
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#include <conio.h>

#include<iostream>
#include<vector>
#include "Client.h"

Client* myClient;

#define DEFAULT_PORT 42069
#define LOGIN_MAIL		"iosub.andrei@mta.ro"
#define LOGIN_PASSWORD	"andrei1234"

void Auth()
{
	bool usernameReceived = false;
	bool passwordReceived = false;
	bool authAccepted = false;
	do
	{
		cout << "Please provide a username" << endl;
		std::string str;
		getline(cin, str);

		str = LOGIN_MAIL;

		myClient->SendString(str);

		if (!myClient->GetBool(usernameReceived))
		{
			cout << "Authentification failed. Leaving..." << endl;
			exit(EXIT_FAILURE);
		}

		cout << "Please provide a password" << endl;

		getline(cin, str);

		str = LOGIN_PASSWORD;

		myClient->SendString(str);

		if (!myClient->GetBool(passwordReceived)) 
		{
			cout << "Authentification failed. Leaving..." << endl;
			exit(EXIT_FAILURE);
		}

		if (!myClient->GetBool(authAccepted))
		{
			cout << "Password or Username incorrect." << endl;
		}
	} 	while (!authAccepted);
}

int main(int argc, char** argv)
{
	myClient = new Client(argc, argv, DEFAULT_PORT);

	if (!myClient->Connect())
	{
		system("pause");
		return 1;
	}

	Auth();

	system("pause");
	system("cls");

	if (myClient->LoadUserInfo())
	{
		myClient->printUserInfo();
	}

	myClient->StartSubRoutine();

	system("pause");

	string buffer;

	while (true)
	{
		//1.
		//Set new password example

		//cout << "Set new password: ";
		//buffer = to_string(5); //codul
		//string line_buffer;
		//getline(cin, line_buffer);
		//buffer += line_buffer;
		//vector<string> vectString = { to_string(5), line_buffer };
		//buffer = PARSER->parseString(vectString, '$');
		//myClient->SendString(buffer);


		//2.
		//Insert new user example

		/*cout << "Insert new user:" << endl;
		vector<string> vectString = {to_string(3)};
		cout << "User Role: 1 - Student, 2 - Professor, 3 - Administrator :" << endl;
		getline(cin, buffer);
		vectString.push_back(buffer);
		cout << "Last Name :" << endl;
		getline(cin, buffer);
		vectString.push_back(buffer);
		cout << "First Name :" << endl;
		getline(cin, buffer);
		vectString.push_back(buffer);
		cout << "Email :" << endl;
		getline(cin, buffer);
		vectString.push_back(buffer);
		cout << "Password :" << endl;
		getline(cin, buffer);
		vectString.push_back(buffer);
		if (atoi(vectString[1].c_str()) == 1) {
			cout << "StudyGroup :" << endl;
			getline(cin, buffer);
			vectString.push_back(buffer);
			cout << "StudyYear :" << endl;
			getline(cin, buffer);
			vectString.push_back(buffer);
		}
		buffer = PARSER->parseString(vectString, '$');
		myClient->SendString(buffer);*/

	}

	WSACleanup();

	system("pause");

	exit(EXIT_SUCCESS);
}