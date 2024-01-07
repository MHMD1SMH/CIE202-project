#include "collectable.h"
#include "gameConfig.h"
#include "game.h"
collectable::collectable(point r_uprleft, game* r_pGame) :
	collidable(r_uprleft, 10, 10, r_pGame)
{
}

collectable::collectable(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	collidable(r_uprleft, r_width, r_height, r_pGame)
{
}

bool collectable::checkCollision(collidable* paddle)
{
	ColliedInfo info = this->isCollided(paddle, this);
	return info.isCollided;
}

void collectable::collisionAction()
{
	//do what should happen when the paddle hit on of the collectables
	pGame->increasePaddleWidth();
}

bool collectable::moveCollectable()
{

	draw(pGame->getWind(), LAVENDER);
	if (this->uprLft.y + this->width +3 <= config.windHeight - config.statusBarHeight) {
		this->uprLft.y += this->height / 2;
		return true;
	}
	return false;
}



color collectable::getColor()
{
	return this->Color;
}

int collectable::getMin()
{
	return stoi(initiatemin);
}

int collectable::getSec()
{
	return stoi(initiatesec);
}

void collectable::draw(window* pWind, color c)
{
	pWind->SetPen(c);
	pWind->SetBrush(c);
	pWind->DrawCircle(this->uprLft.x, this->uprLft.y, this->width);
}

int collectable::getC()
{
	return c;
}

collectables::collectables()
{
}

void collectables::addUpCollectable(point r_uprleft, game* r_pGame)
{
	powerUpTypes test = powerUpTypes(rand() % LastUp);

	switch (0)
	{
	case FireBall:
		arrOfCollectables.push_back(new fireBall(r_uprleft, r_pGame));
		break;
	case WindGlide:
		//arrOfCollectables.push_back();
		arrOfCollectables.push_back(new windGlide(r_uprleft, r_pGame));
		break;
	case WidePaddle:
		//arrOfCollectables.push_back();
		arrOfCollectables.push_back(new widePaddle(r_uprleft, r_pGame));
		break;
	case Magnet:
		arrOfCollectables.push_back(new magnet(r_uprleft, r_pGame));
		//arrOfCollectables.push_back();
		break;
	case MultipleBalls:
		arrOfCollectables.push_back(new multipleBalls(r_uprleft, r_pGame));
		//arrOfCollectables.push_back();
		break;
	default:
		break;
	}

}

void collectables::addDownCollectable(point r_uprleft, game* r_pGame)
{
	powerDownTypes test = powerDownTypes(rand() % LastDown);
	switch (FireBall)
	{
	case NarrowPaddle:
		//arrOfCollectables.push_back();
		break;
	case ReverseDirection:
		//arrOfCollectables.push_back();
		break;
	case QuickSand:
		//arrOfCollectables.push_back();
		break;
	case ZeroDeath:
		//arrOfCollectables.push_back();
		break;
	default:
		break;
	}

}

void collectables::moveCollectables(collidable* paddle, window* pWind)
{
	for (int i = 0; i < arrOfCollectables.size(); i++) {
		if (arrOfCollectables[i]->checkCollision(paddle)) {
			arrOfCollectables[i]->draw(pWind, LAVENDER);
			arrOfCollectables[i]->collisionAction();

		}
		else if (!arrOfCollectables[i]->moveCollectable() && arrOfCollectables[i]->getC() == 0) {
			arrOfCollectables[i]->draw(pWind, LAVENDER);
			arrOfCollectables.erase(arrOfCollectables.begin() +i);
		}
		else if( arrOfCollectables[i]->getC() == 0)
		{
			arrOfCollectables[i]->draw(pWind, arrOfCollectables[i]->getColor());
		}
		else if (arrOfCollectables[i]->ResetAction())
		{

			arrOfCollectables.erase(arrOfCollectables.begin() + i);

		}
	}
}



fireBall::fireBall(point r_uprleft, game* r_pGame) :collectable(r_uprleft, r_pGame)
{

	Color = RED;
	initiatemin = pGame->getTime()->getinmin();
	initiatesec = pGame->getTime()->getinsec();
}


void fireBall::collisionAction()
{
	if (c==0) {
		this->width = 0;
		pGame->setBallColor(ORANGE);
		config.destructPower = 3;
		c += 1;
	}
}

bool fireBall::ResetAction()
{
	if (this->getSec() == stoi(pGame->getTime()->getinsec()) && this->getMin() == stoi(pGame->getTime()->getinmin()) - 1)
	{
		pGame->setBallColor(RED);
		config.destructPower = 1;
		return true;
	}
	return false;
}

windGlide::windGlide(point r_uprleft, game* r_pGame) :collectable(r_uprleft, r_pGame)
{
	Color = BLUE;
}

void windGlide::collisionAction()
{
	pGame->increasePaddleSpeed();

}

bool windGlide::ResetAction()
{
	return false;
}

widePaddle::widePaddle(point r_uprleft, game* r_pGame) :collectable(r_uprleft, r_pGame)
{
	Color = ORANGE;
	initiatemin = pGame->getTime()->getinmin();
	initiatesec = pGame->getTime()->getinsec();
}

void widePaddle::collisionAction()
{

	if (c == 0)
	{
		pGame->increasePaddleWidth();
		c += 1;
	}
}

bool widePaddle::ResetAction()
{
	if (this->getSec() == stoi(pGame->getTime()->getinsec()) && this->getMin() == stoi(pGame->getTime()->getinmin()) -1)
	{
		pGame->decreasePaddleWidth();
		return true;
	}
	return false;
}



magnet::magnet(point r_uprleft, game* r_pGame) :collectable(r_uprleft, r_pGame)
{
	Color = BLACK;
}

void magnet::collisionAction()
{
	pGame->getBall()->Reset();
	pGame->getPaddle()->Reset();

}

bool magnet::ResetAction()
{
	return false;
}

multipleBalls::multipleBalls(point r_uprleft, game* r_pGame) :collectable(r_uprleft, r_pGame)
{
	Color = LIGHTGRAY;
}

void multipleBalls::collisionAction()
{

}

bool multipleBalls::ResetAction()
{
	return false;
}

narrowPaddle::narrowPaddle(point r_uprleft, game* r_pGame) :collectable(r_uprleft, r_pGame)
{
	Color = BLUE;
}

void narrowPaddle::collisionAction()
{
	pGame->decreasePaddleWidth();
}
bool narrowPaddle::ResetAction()
{
	return false;
}
reverseDirection::reverseDirection(point r_uprleft, game* r_pGame) :collectable(r_uprleft, r_pGame)
{
	Color = RED;
}

void reverseDirection::collisionAction()
{
	pGame->reversePaddleDirection();
}

bool reverseDirection::ResetAction()
{
	return false;
}

quickSand::quickSand(point r_uprleft, game* r_pGame) :collectable(r_uprleft, r_pGame)
{
	Color = RED;
}

void quickSand::collisionAction()
{
	pGame->decreasePaddleSpeed();
}

bool quickSand::ResetAction()
{
	return false;
}

zeroDeath::zeroDeath(point r_uprleft, game* r_pGame) :collectable(r_uprleft, r_pGame)
{
	Color = BLACK;
}

void zeroDeath::collisionAction()
{
	pGame->SetScore(-100);//for example
}

bool zeroDeath::ResetAction()
{
	return false;
}
