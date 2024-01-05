#pragma once
#include <iostream>
#include <sstream>
#include <cmath>

//#include "game.h"
#include "gameConfig.h"
#include "Bricks.h"
#include "collidable.h"
#include "CMUgraphicsLib\auxil.h"
using namespace std;
class Ball :public collidable
{
protected:
	point Center;
	int rad, Xinc, Yinc;


public:
	Ball(point ballUprLeft, int rad, int r_height, game* r_pGame);
	void draw(color C, window*);
	void MoveBall();
	ColliedInfo BallCollision(collidable*);
	void collisionAction();
	point GetCenter();
	void SetCenter(point);
	int getRadius();
	int getXinc();
	int getYinc();
	void SetXinc(int);
	void SetYinc(int);
	int GetCenterX();
	void Reset();


};