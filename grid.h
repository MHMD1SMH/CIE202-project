#pragma once

#include "drawable.h"
#include "Bricks.h"


class game;

class grid:public drawable
{
	
	brick*** brickMatrix;		//2D array of brick pointers

	int rows, cols;
public:
	grid(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~grid();
	brick*** GetBrick();
	void draw() const;
	int addBrick(BrickType brkType, point clickedPoint);
	int deletBrick(int i,int j);

};

