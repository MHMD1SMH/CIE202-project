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
	ColliedInfo info = this->isCollided(paddle , this);
	cout << this->uprLft.y << endl;
	return info.isCollided;
}

void collectable::collisionAction()
{
	//do what should happen when the paddle hit on of the collectables
}

bool collectable::moveCollectable()
{
	
	draw(pGame->getWind(),LAVENDER );
	if (this->uprLft.y <= config.windHeight) {
		this->uprLft.y += this->height / 2;
		return true;
	}
	return false;
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

void collectables::addCollectable(point r_uprleft, game* r_pGame)
{
	arrOfCollectables.push_back(collectable(r_uprleft, r_pGame));
}

void collectables::moveCollectables(collidable* paddle,window *pWind)
{
	for (int i = 0; i < arrOfCollectables.size(); i++) {
		if (arrOfCollectables[i].checkCollision(paddle)) {
			arrOfCollectables[i].collisionAction();
			arrOfCollectables[i].draw(pWind, LAVENDER);
			arrOfCollectables.erase(arrOfCollectables.begin()+ i);
		}
		else if (!arrOfCollectables[i].moveCollectable()){
			arrOfCollectables[i].draw(pWind, LAVENDER);
			arrOfCollectables.erase(arrOfCollectables.begin() + i);
		}
		else {
			arrOfCollectables[i].draw(pWind , BLUE);
		}

	}
}
