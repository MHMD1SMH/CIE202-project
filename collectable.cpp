#include "collectable.h"
#include "gameConfig.h"
#include "game.h"
collectable::collectable(point r_uprleft, game* r_pGame):
	collidable(r_uprleft, 10, 10, r_pGame)
{
}

collectable::collectable(point r_uprleft, int r_width, int r_height, game* r_pGame):
	collidable(r_uprleft, r_width, r_height, r_pGame)
{
}

bool collectable::checkCollision(collidable* paddle)
{
	ColliedInfo info = this->isCollided(this, paddle);
	return info.isCollided;
}

void collectable::collisionAction()
{
	//do what should happen when the paddle hit on of the collectables
}

bool collectable::moveCollectable()
{
	if (this->uprLft.y <= config.paddleStartHeight) {
		this->uprLft.y += this->height / 2;
		return true;
	}
	return false;
}

void collectable::draw(window* pWind)
{
	
	pWind->SetPen(BLUE);
	pWind->SetBrush(BLUE);
	pWind->DrawCircle(this->uprLft.x, this->uprLft.y, this->width);
}

collectables::collectables()
{
}

void collectables::addCollectable(point r_uprleft, game* r_pGame)
{
	arrOfCollectables.push_back(collectable(r_uprleft, r_pGame));
}

void collectables::moveCollectables(collidable* paddle,window *pWind)
{
	for (int i = 0; i < arrOfCollectables.size(); i++) {
		if (arrOfCollectables[i].checkCollision(paddle)) {
			arrOfCollectables[i].collisionAction();
			arrOfCollectables.erase(arrOfCollectables.begin()+ i);
		}
		else if (!arrOfCollectables[i].moveCollectable()){
			arrOfCollectables.erase(arrOfCollectables.begin() + i);
		}
		else {
			arrOfCollectables[i].draw(pWind);
		}

	}
}
