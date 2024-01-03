#include "Score.h"

Score::Score()
{
	score = 0;
}

void Score::setScore( int n)
{
	score += n;
}

int Score::getScore() const
{
	return score;
}
