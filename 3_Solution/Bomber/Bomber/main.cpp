#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Singleton.h"
using namespace std;
int main()
{

	Singleton& p1 = Singleton::GetInstance();
	cout << p1.GetVal() << endl;
	Singleton::DestroyInstance();

	Singleton* p2 = Singleton::GetInstancePtr(2);
	cout << p2->GetVal() << endl;
	Singleton::DestroyInstance();

	Singleton::createEvent("Eventul1");
	return 0;
	
}