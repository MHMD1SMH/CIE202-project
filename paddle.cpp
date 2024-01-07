#include "Paddle.h"
#include "game.h"
#include <iostream>
using namespace std;
paddle::paddle(int r_width, int r_height, game* r_pGame):collidable(paddlePlace, r_width, r_height, r_pGame) {
	paddlePlace.x = 600-(150/2);
	paddlePlace.y = 480;
	step=40;
	uprLft.y = paddlePlace.y;
	uprLft.x = paddlePlace.x;
	this->height = config.paddleHeigth;
}
void paddle::draw(color C) const {
	window* pwind = pGame->getWind();
	pwind->SetPen(C);
	pwind->SetBrush(C);
	pwind->DrawRectangle(paddlePlace.x, paddlePlace.y, paddlePlace.x + config.paddleWidth, paddlePlace.y + config.paddleHeigth);
}

bool paddle::windowCollision()
{
	if (paddlePlace.x > 0 && (paddlePlace.x + 200) < 1200)
		return true;
	else return false;
}

void paddle::collisionAction()
{

}

void paddle::movePaddle(bool isRight)
{
	if (windowCollision()) {
		//move as you wish
		if (isRight){
		paddlePlace.x += step;
		uprLft.x = paddlePlace.x;
		}
		else {
			paddlePlace.x -= step;
	     	uprLft.x = paddlePlace.x;
			
		}
	}
}

void paddle::increasePaddleSpeed()
{

	step *= 2;
}

void paddle::increasePaddleWidth()
{
	config.paddleWidth += 100;
	this->width = config.paddleWidth;
}

void paddle::decreasePaddleSpeed()
{
	step /= 1.5;
}

void paddle::decreasePaddleWidth()
{

	config.paddleWidth -= 100;
	this->width = config.paddleWidth;
}

void paddle::reversePaddleDirection()
{
	step *= -1;
}

void paddle::Reset()
{
	paddlePlace.x = 600 - (150 / 2);
	uprLft.x = 600 - (150 / 2);
}
