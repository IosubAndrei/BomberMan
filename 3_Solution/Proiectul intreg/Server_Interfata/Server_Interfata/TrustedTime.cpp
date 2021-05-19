#include "TrustedTime.h"

TrustedTime* TrustedTime::instance = nullptr;

TrustedTime::TrustedTime()
{
}

TrustedTime::~TrustedTime()
{
	destroyInstance();
}

void TrustedTime::destroyInstance()
{
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
}

void TrustedTime::updateTime()
{
	time_t rawtime;
	struct tm* timeinfo;
	char buffer1[80];
	char buffer2[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer1, 80, "%D.", timeinfo);

	strftime(buffer2, 80, "%R.", timeinfo);

	char* p;
	p = strtok(buffer1, "/");
	month = atoi(p);
	p = strtok(nullptr, "/");
	day = atoi(p);
	p = strtok(nullptr, ".");
	year = atoi(p);

	char* q;
	q = strtok(buffer2, ":");
	hour = atoi(q);
	q = strtok(nullptr, ".");
	minute = atoi(q);
}

TrustedTime* TrustedTime::getInstance()
{
	if (instance == nullptr)
		instance = new TrustedTime();
	instance->updateTime();
	return instance;
}

void TrustedTime::printTime()
{
	cout << "Time is : ";
	cout << day << "/" << month << "/" << year << " " << hour << ":" << minute << endl;
}

void TrustedTime::addHours()
{
	if (hour < 23)
	{
		hour++;
	}
	else if (hour == 23)
	{
		hour = 8;
		if (day == 31)
		{
			if (month == 12)
			{
				year++;
				month = 1;
			}
			else
			{
				month++;
			}
			day = 1;
		}
		else
		{
			day++;
		}
	}
}

string TrustedTime::getExactHour()
{

	char buff1[50];
	_itoa(minute, buff1, 10);
	char buff2[3];
	_itoa(hour, buff2, 10);
	char buff3[10];
	_itoa(day, buff3, 10);
	char buff4[10];
	_itoa(month, buff4, 10);
	char buff5[10];
	_itoa(year, buff5, 10);

	strcat(buff1, "/");
	strcat(buff1, buff2);
	strcat(buff1, "/");
	strcat(buff1, buff3);
	strcat(buff1, "/");
	strcat(buff1, buff4);
	strcat(buff1, "/20");
	strcat(buff1, buff5);


	string x = buff1;

	return x;

}

string TrustedTime::getTime()
{
	char buff1[50];
	_itoa(day, buff1, 10);
	char buff2[3];
	_itoa(month, buff2, 10);
	char buff3[10];
	_itoa(year, buff3, 10);
	char buff4[10];
	_itoa(hour, buff4, 10);

	strcat(buff1, "/");
	strcat(buff1, buff2);
	strcat(buff1, "/");
	strcat(buff1, buff3);
	strcat(buff1, "*");
	strcat(buff1, buff4);


	string x = buff1;

	return x;

}