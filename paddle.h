#pragma once
#include "gameConfig.h"
#include "collidable.h"

class paddle:public collidable
{
private:
	point paddlePlace;
	int step;
public:
	paddle(int, int, game* );
	void draw() const;
	bool windowCollision();
	void collisionAction();
	void movePaddle(bool);
};
