#include "PswdHash.h"

PswdHash* PswdHash::instance = nullptr;
int PswdHash::seed = rand() % 99 + 1; //setare de seed

PswdHash::PswdHash()
{
}

string PswdHash::generateSalt()
{
	string salty_boi = "salty";

	for (int index = 0; index < 6; index++) {
		do {
			salty_boi[index] = (salty_boi[index] * seed) % 78;
			salty_boi[index] += 48;
			//ranges between '0' and '~'
		}

		while (salty_boi[index] == '$');
	}

	return salty_boi;
}

PswdHash* PswdHash::getInstance()
{
	if (instance == nullptr)
		instance = new PswdHash;
	return instance;
}

void PswdHash::destroyInstance()
{
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
}

int& PswdHash::extractSeed(string hashedPassword)
{
	string old_seed = "  ";
	for (int index = 1; index < 3; index++) {
		if (hashedPassword[index] == '$')
			break;
		old_seed[index] = hashedPassword[index];
	}

	int int_seed = stoi(old_seed);
	return int_seed;
}

string PswdHash::getPasswordHash(string unhashedPassword, int older_seed)
{
	if (!older_seed)
		seed = rand() % 100 + 1;
	else
		seed = older_seed;

	string salt = generateSalt();
	string long_boi = "$" + to_string(seed) + "$" + salt + "$";

	ULLONG hash = 0;

	unhashedPassword += salt;

	for (int i = 0; i < unhashedPassword.length(); i++)
	{
		hash = (hash * seed) + unhashedPassword[i];
	}
	hash %= ULLONG_MAX;

	long_boi += to_string(hash);
	return long_boi;
}

PswdHash::~PswdHash()
{
	destroyInstance();
}
