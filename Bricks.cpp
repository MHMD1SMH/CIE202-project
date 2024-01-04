#include "Bricks.h"
#include "Game.h"

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

int brick::BrickTybe()
{
	return 0;
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
int normalBrick::BrickTybe()
{
	return 1;
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

int hardBrick::BrickTybe()
{
	return 3;
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

int rockBrick::BrickTybe()
{
	return 0;
}



