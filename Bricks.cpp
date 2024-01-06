#include "Bricks.h"
#include "Game.h"
#include "collectable.h"

////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
brick::brick(point r_uprleft, int r_width, int r_height, game* r_pGame):
	collidable(r_uprleft, r_width, r_height, r_pGame)
{
	strength = 0;
	pWind = pGame->getWind();
}

void brick::collisionAction()
{
}

BrickType brick::BrickTybe()
{
	return BRK_NRM;
}

////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
normalBrick::normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame):
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\NormalBrick.jpg",strength=1;

}
void normalBrick::collisionAction()
{
	//TODO: Add collision action logic

	
	strength--;
	
	pGame->SetScore(1);
	if (!strength)
	{
		pWind->SetPen(LAVENDER);
		pWind->SetBrush(LAVENDER);
		pWind->DrawRectangle(uprLft.x,uprLft.y,uprLft.x+config.brickWidth,uprLft.y+config.brickHeight);
	}
}
BrickType normalBrick::BrickTybe()
{
	return BRK_NRM;
}
////////////////////////////////////////////////////  class hardBrick  /////////////////////////////////
hardBrick::hardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame):
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\HardBrick.jpg", strength = 3;
}

void hardBrick::collisionAction()
{
	//TODO: Add collision action logic
	strength--;
	pGame->SetScore(1);
	if (!strength)
	{
		pWind->SetPen(LAVENDER);
		pWind->SetBrush(LAVENDER);
		pWind->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + config.brickWidth, uprLft.y + config.brickHeight);
	}
	
}

BrickType hardBrick::BrickTybe()
{
	return BRK_HRD;
}

////////////////////////////////////////////////////  class rockBrick  /////////////////////////////////
rockBrick::rockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame):
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\RockBrick.jpg";
}


void rockBrick::collisionAction()
{
	// no thing just change ball dirction

}

BrickType rockBrick::BrickTybe()
{
	return BRK_RCK;
}

////////////////////////////////////////////////////  class PowerUpBrick  /////////////////////////////////


PowerUpBrick::PowerUpBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\PowerUpBrick.jpg";
	strength = 1;
}

void PowerUpBrick::collisionAction()
{

	strength--;
	pGame->SetScore(1);
	if (!strength)
	{
		pWind->SetPen(LAVENDER);
		pWind->SetBrush(LAVENDER);
		pWind->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + config.brickWidth, uprLft.y + config.brickHeight);
	}
	pGame->addCollectable(this->uprLft);
}

BrickType PowerUpBrick::BrickTybe()
{
	return BRK_UP;
}

////////////////////////////////////////////////////  class PowerDownBrick  /////////////////////////////////


PowerDownBrick::PowerDownBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
}

void PowerDownBrick::collisionAction()
{
}

BrickType PowerDownBrick::BrickTybe()
{
	return BRK_DOWN;
}
