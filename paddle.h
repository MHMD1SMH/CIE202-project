#pragma once
#include "gameConfig.h"
#include "collidable.h"

class paddle:public collidable
{
private:
	int step;
public:
	point paddlePlace;
	paddle(int, int, game* );
	void draw( color C) const;
	bool windowCollision();
	void collisionAction();
	void movePaddle(bool);
	void increasePaddleSpeed();
	void increasePaddleWidth();
	void decreasePaddleSpeed();
	void decreasePaddleWidth();
	void reversePaddleDirection();

	void Reset();
};
