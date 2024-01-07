#include "Bricks.h"
#include "Game.h"
#include "collectable.h"

////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
brick::brick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
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
normalBrick::normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\NormalBrick.jpg", strength = 1;

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
		pWind->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + config.brickWidth, uprLft.y + config.brickHeight);
	}
}
BrickType normalBrick::BrickTybe()
{
	return BRK_NRM;
}
////////////////////////////////////////////////////  class hardBrick  /////////////////////////////////
hardBrick::hardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\HardBrick.jpg", strength = 3;
}

void hardBrick::collisionAction()
{
	//TODO: Add collision action logic
	strength-=config.destructPower;
	pGame->SetScore(config.destructPower);
	if (strength <= 0)
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
rockBrick::rockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\RockBrick.jpg";
}


void rockBrick::collisionAction()
{
	// no thing just change ball dirction
	pWind->SetPen(LAVENDER);
	pWind->SetBrush(LAVENDER);
	pWind->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + config.brickWidth, uprLft.y + config.brickHeight);

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
	pGame->addUpCollectable(this->uprLft);
}

BrickType PowerUpBrick::BrickTybe()
{
	return BRK_UP;
}

////////////////////////////////////////////////////  class PowerDownBrick  /////////////////////////////////


PowerDownBrick::PowerDownBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\PowerDownBrick.jpg";
	strength = 1;
}

void PowerDownBrick::collisionAction()
{
	strength--;
	pGame->SetScore(1);
	if (!strength)
	{
		pWind->SetPen(LAVENDER);
		pWind->SetBrush(LAVENDER);
		pWind->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + config.brickWidth, uprLft.y + config.brickHeight);
	}
	pGame->addDownCollectable(this->uprLft);
}

BrickType PowerDownBrick::BrickTybe()
{
	return BRK_DOWN;
}
////////////////////////////////////////////////////  class BombBrick  /////////////////////////////////


BombBrick::BombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\BombBrick.jpg";
	strength = 1;
}

void BombBrick::collisionAction()
{
	strength--;
	pGame->SetScore(4);
	if (!strength)
	{
		int col = uprLft.x / config.brickWidth;
		int row = (uprLft.y - config.toolBarHeight) / config.brickHeight;
		pWind->SetPen(LAVENDER);
		pWind->SetBrush(LAVENDER);
		pWind->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + config.brickWidth, uprLft.y + config.brickHeight);
		if (pGame->getMatrix()[row + 1][col])
		{
			delete pGame->getMatrix()[row + 1][col];
			pGame->getMatrix()[row + 1][col] = nullptr;
			pWind->DrawRectangle(uprLft.x, uprLft.y + config.brickHeight
				, uprLft.x + config.brickWidth, uprLft.y + 2 * config.brickHeight);
		}
		if (pGame->getMatrix()[row - 1][col])
		{
			delete pGame->getMatrix()[row - 1][col];
			pGame->getMatrix()[row - 1][col] = nullptr;
			pWind->DrawRectangle(uprLft.x, uprLft.y - config.brickHeight
				, uprLft.x + config.brickWidth, uprLft.y);
		}
		if (pGame->getMatrix()[row][col + 1])
		{
			delete pGame->getMatrix()[row][col + 1];
			pGame->getMatrix()[row][col + 1] = nullptr;
			pWind->DrawRectangle(uprLft.x + config.brickWidth, uprLft.y,
				uprLft.x + 2 * config.brickWidth, uprLft.y + config.brickHeight);
		}
		if (pGame->getMatrix()[row][col - 1])
		{
			delete pGame->getMatrix()[row][col - 1];
			pGame->getMatrix()[row][col - 1] = nullptr;
			pWind->DrawRectangle(uprLft.x - config.brickWidth, uprLft.y,
				uprLft.x, uprLft.y + config.brickHeight);
		}

	}

}

BrickType BombBrick::BrickTybe()
{
	return BRK_BOM;
}
////////////////////////////////////////////////////  class constructBrick  /////////////////////////////////


constructBrick::constructBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\ConstructBrick.jpg";
	strength = 1;
}

void constructBrick::collisionAction()
{
	strength--;
	pGame->SetScore(1);
	point newp;

	//grid* pGrid = pGame->getGrid();
	int col = uprLft.x / config.brickWidth;
	int row = (uprLft.y - config.toolBarHeight) / config.brickHeight ;
	pWind->SetPen(LAVENDER);
	pWind->SetBrush(LAVENDER);
	/*cout << (pGame->getMatrix()[row + 1][col]) << endl;
	cout << (pGame->getMatrix()[row ][col]) << endl;*/
	
	//pWind->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + config.brickWidth, uprLft.y + config.brickHeight);
	if (!pGame->getMatrix()[row + 1][col] && !(isCollided(this,pGame->getBall()).side == UPPER))
	{
		newp.x = uprLft.x;
		newp.y = uprLft.y + config.brickHeight;
		pGame->getGrid()->addBrick(BRK_NRM, newp);
		config.totalScore += 1;
	}
	cout << (pGame->getMatrix()[row - 1][col]) << endl;
	if (!(pGame->getMatrix()[row - 1][col]))
	{
		newp.x = uprLft.x;
		newp.y = uprLft.y - config.brickHeight;
		pGame->getGrid()->addBrick(BRK_NRM, newp);
		config.totalScore += 1;

	}

	cout << ans.side;
	if (!pGame->getMatrix()[row][col + 1] && !(ans.side == RIGHT))
	{
		newp.x = uprLft.x + config.brickWidth;
		newp.y = uprLft.y;
		pGame->getGrid()->addBrick(BRK_NRM, newp);
		config.totalScore += 1;
	}
	if (!pGame->getMatrix()[row][col - 1] && !(ans.side == LEFT))
	{
		newp.x = uprLft.x - config.brickWidth;
		newp.y = uprLft.y;
		pGame->getGrid()->addBrick(BRK_NRM, newp);
		config.totalScore += 1;

	}


	pGame->getGrid()->draw();
	pWind->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + config.brickWidth, uprLft.y + config.brickHeight);
}

BrickType constructBrick::BrickTybe()
{
	return BRK_CONS;
}
