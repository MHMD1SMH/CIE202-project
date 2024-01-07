#pragma once
#include "collidable.h"

#include <vector>
class collectable : public collidable {
protected:
	color Color;
	string initiatemin;
	string initiatesec;
	int c = 0;
public:
	collectable(point r_uprleft, game* r_pGame);
	collectable(point r_uprleft, int r_width, int r_height, game* r_pGame);

	bool checkCollision(collidable* paddle);

	virtual void collisionAction() = 0;

	bool moveCollectable();
	virtual bool ResetAction()= 0;
	color getColor();
	int getMin();
	int getSec();
	void draw(window* pwind, color c);
	int getC();
};

enum powerUpTypes {
	FireBall,
	WindGlide,
	WidePaddle,
	Magnet,
	MultipleBalls,
	LastUp
};

class windGlide :public collectable {
public:
	windGlide(point r_uprleft, game* r_pGame);
	void collisionAction() override;
	bool ResetAction() override ;
};

class fireBall :public collectable {
public:
	fireBall(point r_uprleft, game* r_pGame);
	void collisionAction()override;
	bool ResetAction() override;
};

class widePaddle :public collectable {
public:
	widePaddle(point r_uprleft, game* r_pGame);
	void collisionAction()override;
	bool ResetAction() override;
};

class magnet :public collectable {
public:
	magnet(point r_uprleft, game* r_pGame);
	void collisionAction()override;
	bool ResetAction() override;
};

class multipleBalls :public collectable {
public:
	multipleBalls(point r_uprleft, game* r_pGame);
	void collisionAction()override;
	bool ResetAction() override;
};

enum powerDownTypes {
	NarrowPaddle,
	ReverseDirection,
	QuickSand,
	ZeroDeath,
	LastDown
};

class narrowPaddle :public collectable {
public:
	narrowPaddle(point r_uprleft, game* r_pGame);
	void collisionAction()override;
	bool ResetAction() override;
};

class 	reverseDirection :public collectable {
public:
	reverseDirection(point r_uprleft, game* r_pGame);
	void collisionAction()override;
	bool ResetAction() override;
};

class quickSand :public collectable {
public:
	quickSand(point r_uprleft, game* r_pGame);
	void collisionAction()override;
	bool ResetAction() override;
};

class zeroDeath :public collectable {
public:
	zeroDeath(point r_uprleft, game* r_pGame);
	void collisionAction()override;
	bool ResetAction() override;
};

class collectables {
private:
	vector <collectable*>  arrOfCollectables;
public:
	collectables();
	void addUpCollectable(point r_uprleft, game* r_pGame);
	void addDownCollectable(point r_uprleft, game* r_pGame);
	void moveCollectables(collidable* paddle, window* pWind);
};