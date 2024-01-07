#pragma once

//This file contains all classes bricks classes 
#include "collidable.h"

enum BrickType	//add more brick types
{
	BRK_NRM,	//Normal Brick
	BRK_HRD,	//Hard Brick
	BRK_RCK, 	//Rock Brick
	BRK_UP, 	
	BRK_DOWN,
	BRK_BOM,
	BRK_CONS

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
	virtual BrickType BrickTybe() = 0 ;
	
};


////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
class normalBrick :public brick
{
public:
	normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	 void collisionAction() override;
	 BrickType BrickTybe();
};

////////////////////////////////////////////////////  class hardBrick  /////////////////////////////////
class hardBrick :public brick
{
public:
	hardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction() override;
	BrickType BrickTybe();
};
////////////////////////////////////////////////////  class rockBrick  /////////////////////////////////
class rockBrick :public brick
{
public:
	rockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction()override;
	BrickType BrickTybe();
};
////////////////////////////////////////////////////  class PowerUpBrick  /////////////////////////////////
class PowerUpBrick :public brick
{
public:
	PowerUpBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction()override;
	BrickType BrickTybe();
};
////////////////////////////////////////////////////  class PowerDownBrick  /////////////////////////////////
class PowerDownBrick :public brick
{
public:
	PowerDownBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction()override;
	BrickType BrickTybe();
};
////////////////////////////////////////////////////  class BombBrick  /////////////////////////////////
class BombBrick :public brick
{
public:
	BombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction()override;
	BrickType BrickTybe();
};
////////////////////////////////////////////////////  class constructBrick  /////////////////////////////////
class constructBrick :public brick
{
public:
	constructBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction()override;
	BrickType BrickTybe();
};



