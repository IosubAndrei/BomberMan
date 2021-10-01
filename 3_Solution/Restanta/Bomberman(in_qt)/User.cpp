#include "User.h"

User::User(std::string userData, char delim)
{
	/*
	voi baga o cifra la inceput care va fi id-ul, asa ca va trebui sa folosesc Parser
	userID -> field = 0
	lastName -> field = 1
	firstName -> field = 2
	joinedDate -> field = 3
	email -> field = 4
	password -> field = 5
	role -> field = 6
	*/
	
	std::vector<std::string> vect = Parser::getInstance()->unparseString(userData, delim);

	int field = 0;
	for (auto it = vect.begin(); it != vect.end(); it++)
	{
		switch (field)
		{
		case 0: // userID
		{
			setUserID(atoi((*it).c_str()));
			field++;
			break;
		}
		case 1: // lastName
		{
			setUserLastName(*it);
			field++;
			break;
		}
		case 2: // firstname
		{
			setUserFirstName(*it);
			field++;
			break;
		}
		case 3: // joinedDate
		{
			setJoinedDate(*it);
			field++;
			break;
		}
		case 4: // email
		{
			setEmail(*it);
			field++; 
			break;
		}
		case 5: // password
		{
			setPassword(*it);
			field++; 
			break;
		}
		case 6: // role
		{
			setRole(atoi((*it).c_str()));
			field++; 
			break;
		}
		}
		
	}

	
	//strtok nu ma lasa sa il folosesc
	/*int n = userData.length() + 1;
	char str[n];
	char* pch;
	printf("Splitting string \"%s\" into tokens:\n", str);
	pch = strtok(str, " ,.-");
	while (pch != NULL)
	{
		printf("%s\n", pch);
		pch = strtok(NULL, " ,.-");
	}*/


}

User::User()
{
}

void User::setUserFirstName(std::string name)
{
	firstName = name;
}

void User::setUserLastName(std::string name)
{
	lastName = name;
}

void User::setEmail(std::string newEmail)
{
	email = newEmail;
}

void User::setPassword(std::string newPassword)///////Make use of the SQL Manager
{
	password = newPassword;
}

void User::setJoinedDate(std::string newJoinedDate)
{
	joinedDate = newJoinedDate;
}

void User::setUserID(int newID)
{
	userID = newID;
}

void User::setRole(int newRole)
{
	role = newRole;
}


void User::setConnectionData(std::string _LastName, std::string _FirstName, std::string _JoinedDate, std::string _email, int _ID, int _role)
{
	setUserFirstName(_FirstName);
	setUserLastName(_LastName);
	setEmail(_email);
	setJoinedDate(_JoinedDate);
	setUserID(_ID);
	setRole(_role);
}

std::string User::getUserFirstName()
{
	return firstName;
}

std::string User::getUserLastName()
{
	return lastName;
}

std::string User::getUserFullName()
{
	return firstName + lastName;
}

std::string User::getUserJoinDate()
{
	return joinedDate;
}

std::string User::getUserEmail()
{
	return email;
}

int User::getUserRole()
{
	return role;
}


int User::getUserID()
{
	return userID;
}

User::~User()
{
	lastName.erase();
	firstName.erase();
}

