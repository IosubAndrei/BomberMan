#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
class Singleton {  // SINGLETON - POT FACE OBIECTE DOAR FOLOSIND GETINSTANCE
public:
	static Singleton& GetInstance();
	static Singleton* GetInstancePtr(int v);
	static void DestroyInstance();
	int GetVal() { return val; }
	static void createEvent(string Event);

private:
	Singleton(int v = 5) : val(v) {}
	Singleton(const Singleton& S) : val(S.val) {}
	~Singleton() { ; }
	int val;

	static Singleton* mpInstance;
};
