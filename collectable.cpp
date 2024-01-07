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
	if (this->uprLft.y + this->width <= config.windHeight - config.statusBarHeight) {
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
			arrOfCollectables[i]->collisionAction();
			arrOfCollectables[i]->draw(pWind, LAVENDER);
			
		}
		else if (!arrOfCollectables[i]->moveCollectable()) {
			arrOfCollectables[i]->draw(pWind, LAVENDER);
			arrOfCollectables.erase(arrOfCollectables.begin() + i);
		}
		else {
			arrOfCollectables[i]->draw(pWind, arrOfCollectables[i]->getColor());
		}
		
	}
}



fireBall::fireBall(point r_uprleft, game* r_pGame) :collectable(r_uprleft, r_pGame)
{
	Color = RED;
}

void fireBall::collisionAction()
{
	pGame->setBallColor(ORANGE);
	config.destructPower = 3;
}

windGlide::windGlide(point r_uprleft, game* r_pGame) :collectable(r_uprleft, r_pGame)
{
	Color = BLUE;
}

void windGlide::collisionAction()
{
	pGame->increasePaddleSpeed();

}

widePaddle::widePaddle(point r_uprleft, game* r_pGame) :collectable(r_uprleft, r_pGame)
{
	Color = ORANGE;
}

void widePaddle::collisionAction()
{

	initiatemin = pGame->getTime()->getinmin();
	initiatesec = pGame->getTime()->getinsec();
	pGame->increasePaddleWidth();
}

void widePaddle::Reset()
{
	pGame->decreasePaddleWidth();
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

multipleBalls::multipleBalls(point r_uprleft, game* r_pGame) :collectable(r_uprleft, r_pGame)
{
	Color = LIGHTGRAY;
}

void multipleBalls::collisionAction()
{

}

narrowPaddle::narrowPaddle(point r_uprleft, game* r_pGame) :collectable(r_uprleft, r_pGame)
{
	Color = BLUE;
}

void narrowPaddle::collisionAction()
{
	pGame->decreasePaddleWidth();
}
reverseDirection::reverseDirection(point r_uprleft, game* r_pGame) :collectable(r_uprleft, r_pGame)
{
	Color = RED;
}

void reverseDirection::collisionAction()
{
	pGame->reversePaddleDirection();
}

quickSand::quickSand(point r_uprleft, game* r_pGame) :collectable(r_uprleft, r_pGame)
{
	Color = RED;
}

void quickSand::collisionAction()
{
	pGame->decreasePaddleSpeed();
}

zeroDeath::zeroDeath(point r_uprleft, game* r_pGame) :collectable(r_uprleft, r_pGame)
{
	Color = BLACK;
}

void zeroDeath::collisionAction()
{
	pGame->SetScore(-100);//for example
}