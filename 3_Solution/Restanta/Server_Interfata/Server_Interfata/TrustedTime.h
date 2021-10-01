#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class TrustedTime
{
	TrustedTime();
	~TrustedTime();
	TrustedTime(TrustedTime& copyInstance) = delete;
	static TrustedTime* instance;
	int	day;
	int	month;
	int	year;
	int	minute;
	int	hour;

	void updateTime();
public:
	static TrustedTime* getInstance();
	static void destroyInstance();

	void printTime();
	int	getHour() { return hour; };
	int	getDay() { return day; };
	int	getMonth() { return month; };
	int	getYear() { return year; };
	void addHours();
	string getExactHour();
	string getTime();
};

