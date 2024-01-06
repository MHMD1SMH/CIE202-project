#include "Score.h"

Score::Score()
{
	score = 0;
}

void Score::setScore( int n)
{
	score += n;
}

void Score::Reset()
{
	score = 0;
}

int Score::getScore() const
{
	return score;
}
