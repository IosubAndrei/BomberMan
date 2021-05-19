#pragma once
#include <iostream>
#include <list>
#include <string>

using namespace std;

//unsigned long long max value

#ifndef ULLONG_MAX  
#define ULLONG_MAX 18446744073709551615
#endif // !ULLONG_MAX

#ifndef ULLONG
#define ULLONG unsigned long long
#endif // !ULLONG


class PswdHash
{
private:

	PswdHash();
	PswdHash(PswdHash* copyInstance) = delete;
	~PswdHash();

	static int seed;
	static PswdHash* instance;


	string generateSalt();
public:

	static PswdHash* getInstance();
	static void destroyInstance();

	int& extractSeed(string hashedPassword); // get seed from parsed hash string
	string getPasswordHash(string unhashedPassword, int older_seed = 0); // when you need a password, older_seed = 0

};


