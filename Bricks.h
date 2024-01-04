#pragma once

//This file contains all classes bricks classes 
#include "collidable.h"

enum BrickType	//add more brick types
{
	BRK_NRM,	//Normal Brick
	BRK_HRD,	//Hard Brick
	BRK_RCK 	//Rock Brick

	//TODO: Add more types
};

////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
//Base class for all bricks
class brick :public collidable
{
public:
	int strength;
	window* pWind;

public:
	brick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction() override;
	virtual int BrickTybe() ;
	
};


////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
class normalBrick :public brick
{
public:
	normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	 void collisionAction() override;
	int BrickTybe();
};

////////////////////////////////////////////////////  class hardBrick  /////////////////////////////////
class hardBrick :public brick
{
public:
	hardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction() override;
	int BrickTybe();
};
////////////////////////////////////////////////////  class rockBrick  /////////////////////////////////
class rockBrick :public brick
{
public:
	rockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction()override;
	int BrickTybe();
};



