#pragma once
#include <ctime>
class Time
{
private:
	time_t start;
	time_t now;
	int dif;
	int min;
public:
	Time();
	int getinsec();
	int getinmin();

};

