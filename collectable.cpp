#include "collectable.h"
#include "gameConfig.h"
#include "game.h"
collectable::collectable(point r_uprleft, game* r_pGame) :
	collidable(r_uprleft, 10, 10, r_pGame)
{
}

bool collectable::checkCollision(collidable* paddle)
{
	ColliedInfo info = this->isCollided(pGame->getPaddle(), this);
	return info.isCollided;
}

void collectable::collisionAction()
{
	//do what should happen when the paddle hit on of the collectables
	pGame->increasePaddleWidth();
}

bool collectable::moveCollectable()
{

	draw(LAVENDER);
	if (this->uprLft.y + this->width + 3 <= config.windHeight - config.statusBarHeight) {
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

void collectable::draw( color c)
{
	pGame->getWind()->SetPen(c);
	pGame->getWind()->SetBrush(c);
	pGame->getWind()->DrawCircle(this->uprLft.x, this->uprLft.y, this->width);
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

	switch (test)
	{
	case FireBall:
		arrOfCollectables.push_back(new fireBall(r_uprleft, r_pGame));
		break;
	case WindGlide:
		arrOfCollectables.push_back(new windGlide(r_uprleft, r_pGame));
		break;
	case WidePaddle:
		arrOfCollectables.push_back(new widePaddle(r_uprleft, r_pGame));
		break;
	case Magnet:
		arrOfCollectables.push_back(new magnet(r_uprleft, r_pGame));
		break;
	default:
		break;
	}

}

void collectables::addDownCollectable(point r_uprleft, game* r_pGame)
{
	powerDownTypes test = powerDownTypes(rand() % LastDown);
	switch (ReverseDirection)
	{
	case NarrowPaddle:
		arrOfCollectables.push_back(new narrowPaddle(r_uprleft, r_pGame));
		break;
	case ReverseDirection:
		arrOfCollectables.push_back(new reverseDirection(r_uprleft, r_pGame));
		break;
	case QuickSand:
		arrOfCollectables.push_back(new quickSand(r_uprleft, r_pGame));
		break;
	case ZeroDeath:
		arrOfCollectables.push_back(new zeroDeath(r_uprleft,r_pGame));
		break;
	default:
		break;
	}

}

void collectables::moveCollectables(collidable* paddle, window* pWind)
{
	for (int i = 0; i < arrOfCollectables.size(); i++) {
		if (arrOfCollectables[i]->checkCollision(paddle) && arrOfCollectables[i]->getC() == 0) {
			arrOfCollectables[i]->draw(LAVENDER);
			arrOfCollectables[i]->collisionAction();
			if (arrOfCollectables[i]->getC() == 0)
			{
				arrOfCollectables.erase(arrOfCollectables.begin() + i);
			}
		}
		else if (!arrOfCollectables[i]->moveCollectable() && arrOfCollectables[i]->getC() == 0) {
			arrOfCollectables[i]->draw(LAVENDER);
			arrOfCollectables.erase(arrOfCollectables.begin() + i);
		}
		else if (arrOfCollectables[i]->getC() == 0)
		{
			arrOfCollectables[i]->draw(arrOfCollectables[i]->getColor());
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
	if (c == 0) {
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
	initiatemin = pGame->getTime()->getinmin();
	initiatesec = pGame->getTime()->getinsec();
}

void windGlide::collisionAction()
{
	if (c == 0) {
		this->width = 0;
		pGame->increasePaddleSpeed();
		c += 1;
	}

}

bool windGlide::ResetAction()
{
	if (this->getSec() == stoi(pGame->getTime()->getinsec()) && this->getMin() == stoi(pGame->getTime()->getinmin()) - 1)
	{
		pGame->decreasePaddleSpeed();
		return true;
	}
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
	if (this->getSec() == stoi(pGame->getTime()->getinsec()) && this->getMin() == stoi(pGame->getTime()->getinmin()) - 1)
	{
		pGame->decreasePaddleWidth();
		return true;
	}
	return false;
}



magnet::magnet(point r_uprleft, game* r_pGame) :collectable(r_uprleft, r_pGame)
{
	Color = BLACK;
	initiatemin = pGame->getTime()->getinmin();
	initiatesec = pGame->getTime()->getinsec();
}

void magnet::collisionAction()
{
	pGame->getBall()->setStuck(1);
}

bool magnet::ResetAction()
{

	return false;
}

narrowPaddle::narrowPaddle(point r_uprleft, game* r_pGame) :collectable(r_uprleft, r_pGame)
{
	Color = BLUE;
	initiatemin = pGame->getTime()->getinmin();
	initiatesec = pGame->getTime()->getinsec();
}

void narrowPaddle::collisionAction()
{
	if (c == 0)
	{
		pGame->decreasePaddleWidth();
		c += 1;
	}
}
bool narrowPaddle::ResetAction()
{
	if (this->getSec() == stoi(pGame->getTime()->getinsec()) && this->getMin() == stoi(pGame->getTime()->getinmin()) - 1)
	{
		pGame->increasePaddleWidth();
		return true;
	}
	return false;
}
reverseDirection::reverseDirection(point r_uprleft, game* r_pGame) :collectable(r_uprleft, r_pGame)
{
	Color = YELLOW;
	initiatemin = pGame->getTime()->getinmin();
	initiatesec = pGame->getTime()->getinsec();
}

void reverseDirection::collisionAction()
{
	if (c == 0&&pGame->getPaddle()->getStep()>0)
	{
		pGame->reversePaddleDirection();
		c += 1;
	}
}

bool reverseDirection::ResetAction()
{
	if (this->getSec() == stoi(pGame->getTime()->getinsec()) && this->getMin() == stoi(pGame->getTime()->getinmin()) - 2)
	{
		pGame->reversePaddleDirection();
		return true;
	}
	return false;
}

quickSand::quickSand(point r_uprleft, game* r_pGame) :collectable(r_uprleft, r_pGame)
{
	Color = RED;
	initiatemin = pGame->getTime()->getinmin();
	initiatesec = pGame->getTime()->getinsec();
}

void quickSand::collisionAction()
{
	if (c == 0)
	{
		pGame->decreasePaddleSpeed();
		c += 1;
	}
}

bool quickSand::ResetAction()
{
	if (this->getSec() == stoi(pGame->getTime()->getinsec()) && this->getMin() == stoi(pGame->getTime()->getinmin()) - 1)
	{
		pGame->increasePaddleSpeed();
		return true;
	}
	return false;
}

zeroDeath::zeroDeath(point r_uprleft, game* r_pGame) :collectable(r_uprleft, r_pGame)
{
	Color = BLACK;
	initiatemin = pGame->getTime()->getinmin();
	initiatesec = pGame->getTime()->getinsec();
}

void zeroDeath::collisionAction()
{
	pGame->SetScore(-100);
}

bool zeroDeath::ResetAction()
{
	return false;
}
