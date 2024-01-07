#include "collidable.h"
#include <iostream>

collidable::collidable(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	drawable(r_uprleft, r_width, r_height, r_pGame)
{
}
ColliedInfo collidable::isCollided(const  collidable* object1, const collidable* ballCenter)
{
	
	ans.isCollided = false;
	
	if (
		((object1->uprLft.x + object1->width) <= (ballCenter->uprLft.x - ballCenter->width-5)  ||
		(object1->uprLft.y  + object1->height) <= (ballCenter->uprLft.y - ballCenter->height-5)) ||
		(object1->uprLft.x >= (ballCenter->uprLft.x + ballCenter->width +5) ||
		object1->uprLft.y >= (ballCenter->uprLft.y + ballCenter->height+5))
		)
	{
		return ans;
	}
	ans.isCollided = true;
	if (object1->uprLft.y <= ballCenter->uprLft.y &&
		ballCenter->uprLft.x + ballCenter->width - 5 >= object1->uprLft.x &&
		ballCenter->uprLft.x - ballCenter->width + 5 <= object1->uprLft.x + object1->width)
	{
		ans.side = UPPER;
	}
	else if (object1->uprLft.y + object1->height >= ballCenter->uprLft.y &&
		ballCenter->uprLft.x + ballCenter->width - 5 >= object1->uprLft.x &&
		ballCenter->uprLft.x - ballCenter->width + 5 <= object1->uprLft.x + object1->width)
	{
		ans.side = LOWER;
	}
	else if (object1->uprLft.x >= ballCenter->uprLft.x + ballCenter->width - 5 &&
		ballCenter->uprLft.y + ballCenter->width >= object1->uprLft.y &&
		ballCenter->uprLft.y - ballCenter->width <= object1->uprLft.y + object1->height)
	{
		ans.side = RIGHT;
	}
	else if (object1->uprLft.x + object1->width <= ballCenter->uprLft.x - ballCenter->width + 5 &&
		ballCenter->uprLft.y + ballCenter->width >= object1->uprLft.y &&
		ballCenter->uprLft.y - ballCenter->width <= object1->uprLft.y + object1->height)
	{
		ans.side = LEFT;
	}
	return ans;
}

int collidable::DeflectedAngle(collidable* object1, collidable* ball)
{
	deflectedDistance = abs(((object1->uprLft.x) + ((object1->width) / 2.0)) - (ball->uprLft.x));
	deflectedangle = 90 - (45.0 /( object1->width / 2)) * deflectedDistance;
	return deflectedangle;
}
