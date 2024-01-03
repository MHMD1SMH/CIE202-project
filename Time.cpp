#include "Time.h"

Time::Time()
{
	start = time(NULL);
	dif = 0;
	min = 0;
}

int Time::getinsec()
{
	now = time(NULL);

	/*if (dif = 3 )
	{
		min += 1;
		dif = 0;
	}*/
	dif = now - start;
	if (dif == 60)
	{
		
		min += dif / 60;
		start = now;
	}
	return dif;
}

int Time::getinmin()
{
	return min;
}
