#pragma once
#include "collidable.h"

#include <vector>
class collectable : public collidable {
public:
	collectable(point r_uprleft, game* r_pGame);
	collectable(point r_uprleft, int r_width, int r_height, game* r_pGame);
	bool checkCollision(collidable* paddle);
	void collisionAction() override;
	bool moveCollectable();
	void draw(window* pwind, color c);
};
class collectables {
private:
	vector <collectable> arrOfCollectables;
public:
	collectables();
	void addCollectable(point r_uprleft, game* r_pGame);
	void moveCollectables(collidable* paddle, window* pWind);
};