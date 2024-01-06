#pragma once
#include <ctime>
#include <iostream>
using namespace std;
class Time
{
private:
	time_t start;
	time_t now;
	int dif;
	int min;
	bool initialize;
	int c = 0;
public:
	Time(bool initialize);
	string getinsec();
	string getinmin();
	void setInit(bool ini);
	void Reset();
	void setContinue();


};

