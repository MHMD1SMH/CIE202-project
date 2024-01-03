#include "Lives.h"

Live::Live()
{
	numperOfLives = 3;
}

void Live::setLive()
{
	numperOfLives -= 1;
}

int Live::getLive()
{
	return numperOfLives;
}


