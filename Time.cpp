#include "Time.h"

#include <string>

Time::Time(bool initialize)
{
	this->initialize = initialize;
	start = time(NULL);
	dif = 0;
	min = 0;
}

string Time::getinsec()
{

	if (initialize && c == 0)
	{
		start = time(NULL);

		c += 1;
	}
	if (initialize)
	{

		now = time(NULL);
		dif = now - start;

		if (dif == 60)
		{

			min += 1;
			start = now;
		}
	}
	if (dif < 10)
	{
		return "0" + to_string(dif);
	}
	return to_string(dif);
}

string Time::getinmin()
{

	if (min < 10)
	{
		return "0" + to_string(min);
	}
	return to_string(min);

}

void Time::setInit(bool ini)
{
	initialize = ini;
}

void Time::Reset()
{

	dif = 0;
	min = 0;
}



void Time::setContinue()
{
	now = time(NULL);
	start = now - dif;
}


