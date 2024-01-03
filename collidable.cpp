#include "collidable.h"
#include <iostream>

collidable::collidable(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	drawable(r_uprleft, r_width, r_height, r_pGame)
{
}
ColliedInfo collidable::isCollided(const  collidable* object1, const collidable* ballCenter)
{
	ColliedInfo ans;
	ans.isCollided = false;
	// Right Side of object one && Left side of object two
	//if (object1->uprLft.x + object1->width == object2->uprLft.x ){
	//	if (object1->uprLft.y <= object2->uprLft.y && object1->uprLft.y >= object2->uprLft.y + object2->height)
	//	{
	//		ans.isCollided = 1;
	//		ans.PointOfCollision.x = object1->uprLft.x + object1->width ;
	//		ans.PointOfCollision.y = object1->uprLft.y + object1->height/2;
	//	}
	//	else if (object1->uprLft.y + object1->height >= object2->uprLft.y && object1->uprLft.y +object1->height <= object2->uprLft.y + object2->height)
	//	{
	//		ans.isCollided = 1;
	//		ans.PointOfCollision.x = object1->uprLft.x + object1->width;
	//		ans.PointOfCollision.y = object2->uprLft.y + object2->height / 2;
	//	}
	//	else if (object2->uprLft.y <= object1->uprLft.y && object2->uprLft.y +object2->height >= object1->uprLft.y + object1->height)
	//	{
	//		ans.isCollided = 1;
	//		ans.PointOfCollision.x = object1->uprLft.x + object1->width;
	//		ans.PointOfCollision.y = object2->uprLft.y + object2->height / 2;
	//	}
	//	ans.side =LEFT ;
	//}
	//// Left Side of object one && Right side of object two
	//if (object1->uprLft.x == object2->uprLft.x +object2->width){
	//	if (object1->uprLft.y <= object2->uprLft.y && object1->uprLft.y >= object2->uprLft.y + object2->height)
	//	{
	//		ans.isCollided = 1;
	//		ans.PointOfCollision.x = object1->uprLft.x ;
	//		ans.PointOfCollision.y = object1->uprLft.y + object1->height/2;
	//	}
	//	else if (object1->uprLft.y + object1->height >= object2->uprLft.y && object1->uprLft.y +object1->height <= object2->uprLft.y + object2->height)
	//	{
	//		ans.isCollided = 1;
	//		ans.PointOfCollision.x = object1->uprLft.x ;
	//		ans.PointOfCollision.y = object2->uprLft.y + object2->height / 2;
	//	}
	//	else if (object2->uprLft.y <= object1->uprLft.y && object2->uprLft.y +object2->height >= object1->uprLft.y + object1->height)
	//	{
	//		ans.isCollided = 1;
	//		ans.PointOfCollision.x = object1->uprLft.x ;
	//		ans.PointOfCollision.y = object2->uprLft.y + object2->height / 2;
	//	}
	//	ans.side = RIGHT;
	//}
	//// upper Side of object one && lower side of object two
	//if (object1->uprLft.y == object2->uprLft.y +object2->height){
	//	if (object1->uprLft.x <= object2->uprLft.x && object1->uprLft.x >= object2->uprLft.x + object2->width)
	//	{
	//		ans.isCollided = 1;
	//		ans.PointOfCollision.x = object1->uprLft.x +object1->width/2 ;
	//		ans.PointOfCollision.y = object1->uprLft.y ;
	//	}
	//	else if (object2->uprLft.x <= object1->uprLft.x && object2->uprLft.x >= object1->uprLft.x + object1->width)
	//	{
	//		ans.isCollided = 1;
	//		ans.PointOfCollision.x = object1->uprLft.x + object1->width / 2;
	//		ans.PointOfCollision.y = object2->uprLft.y ;
	//	}	
	//	else if (object2->uprLft.x >= object1->uprLft.x && object2->uprLft.x +object2->width <= object1->uprLft.x + object1->width)
	//	{
	//		ans.isCollided = 1;
	//		ans.PointOfCollision.x = object2->uprLft.x + object2->width / 2;
	//		ans.PointOfCollision.y = object2->uprLft.y ;
	//	}
	//	ans.side = LOWER;
	//}
	//// lower Side of object one && upper side of object two
	//if (object1->uprLft.y + object1->height == object2->uprLft.y ){
	//	if (object1->uprLft.x  <= object2->uprLft.x && object1->uprLft.x >= object2->uprLft.x + object2->width)
	//	{
	//		ans.isCollided = 1;
	//		ans.PointOfCollision.x = object1->uprLft.x +object1->width/2 ;
	//		ans.PointOfCollision.y = object1->uprLft.y + object1->height;
	//	}
	//	else if (object2->uprLft.x <= object1->uprLft.x && object2->uprLft.x >= object1->uprLft.x + object1->width)
	//	{
	//		ans.isCollided = 1;
	//		ans.PointOfCollision.x = object2->uprLft.x + object2->width / 2;
	//		ans.PointOfCollision.y = object1->uprLft.y + object1->height ;
	//	}	
	//	else if (object2->uprLft.x >= object1->uprLft.x && object2->uprLft.x +object2->width <= object1->uprLft.x + object1->width)
	//	{
	//		ans.isCollided = 1;
	//		ans.PointOfCollision.x = object2->uprLft.x + object2->width / 2;
	//		ans.PointOfCollision.y = object2->uprLft.y + object1->height;
	//	}
	//	ans.side = UPPER;
	//}

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
	deflectedangle = 90 - (3.0 / 5.0) * deflectedDistance;
	return deflectedangle;
}
