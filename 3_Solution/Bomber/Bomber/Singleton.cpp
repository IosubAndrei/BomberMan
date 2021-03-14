#include "Singleton.h"

Singleton* Singleton::mpInstance = nullptr;


Singleton& Singleton::GetInstance()
{
	if (mpInstance == nullptr)
		mpInstance = new Singleton;
	return *mpInstance;
}

Singleton* Singleton::GetInstancePtr(int v)
{
	if (mpInstance == nullptr)
		mpInstance = new Singleton(v); 
	else
		mpInstance->val = v;
	return mpInstance;
}

void Singleton::DestroyInstance()
{
	if (mpInstance == nullptr)
		return;
	delete mpInstance;
	mpInstance = nullptr;
}

void Singleton::createEvent(string Event)
{
	cout << "Evenimentul- " << Event << endl;
}
