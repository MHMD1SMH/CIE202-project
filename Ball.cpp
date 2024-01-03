#include "Ball.h"

Ball::Ball(point ballUprLeft, int rad, int Hrad, game* r_pGame)
	:collidable(ballUprLeft, rad, Hrad, r_pGame)
{
	this->Center = ballUprLeft;
	this->rad = rad;
	Xinc = 0, Yinc = rad;
	// pWind = pGame->getWind();

}
void Ball::draw(color C, window* pWind) {
	//  bool bDragging = false;

	color c = C;
	pWind->SetPen(c);
	pWind->SetBrush(c);
	pWind->DrawCircle(Center.x, Center.y, rad);

}


void Ball::MoveBall(collidable* Paddle, brick***  Brick, window* pWind)
{
	/// if ball went lower than the paddle
	//if (Center.y >= 490) {

	//	Center.y = 440;
	//	Center.x = config.windWidth / 2;

	//}


	if ((Center.x <= rad) || (Center.x >= config.windWidth - rad) ||
		(isCollided(Paddle, this).isCollided && ((isCollided(Paddle, this).side == RIGHT) || (isCollided(Paddle, this).side == LEFT)))) {
		Xinc = -Xinc;
	}
	else if ((Center.y <= rad + config.toolBarHeight + 4) || (Center.y >= config.windHeight - rad - config.statusBarHeight - 4) ||
		(isCollided(Paddle, this).isCollided && ((isCollided(Paddle, this).side == UPPER) || (isCollided(Paddle, this).side == LOWER)))) {
		if (isCollided(Paddle, this).isCollided) {
			if (Xinc < 0)
				Xinc = -rad;
			else
				Xinc = rad;
			if (Yinc < 0)
				Yinc = -rad;
			else
				Yinc = rad;
			Yinc = -Yinc * abs(sin(DeflectedAngle(Paddle, this) * (3.14 / 180)));
			Xinc = Xinc * abs(cos(DeflectedAngle(Paddle, this) * (3.14 / 180)));
		}
		else {
			Yinc = -Yinc;
		}
	}
	for (int i = 0; i < (config.gridHeight / config.brickHeight); i++) {

		for (int j = 0; j < (config.windWidth / config.brickWidth); j++)
		{
			if (Brick[i][j] && isCollided(Brick[i][j], this).isCollided &&
				(isCollided(Brick[i][j], this).side == LOWER || isCollided(Brick[i][j], this).side == UPPER)) {
				Yinc = -Yinc;
				if (Brick[i][j]->BrickTybe() != 0)
				{

					Brick[i][j]->collisionAction();

					if (Brick[i][j]->strength == 0) {
						delete Brick[i][j];

						Brick[i][j] = nullptr;

						pWind->SetPen(LAVENDER);
						pWind->SetBrush(LAVENDER);
						pWind->DrawRectangle(j * config.brickWidth,
							i * config.brickHeight + config.toolBarHeight,
							j * config.brickWidth + config.brickWidth,
							i * config.brickHeight + config.brickHeight + config.toolBarHeight);
					}
				}
						break;
			}
			if (Brick[i][j] && isCollided(Brick[i][j], this).isCollided &&
				(isCollided(Brick[i][j], this).side == LEFT || isCollided(Brick[i][j], this).side == RIGHT)) {
				Xinc = -Xinc;
				if (Brick[i][j]->BrickTybe() != 0)
				{

					Brick[i][j]->collisionAction();
					if (Brick[i][j]->strength == 0)
					{

						delete Brick[i][j];
						Brick[i][j] = nullptr;
						pWind->SetPen(LAVENDER);
						pWind->SetBrush(LAVENDER);
						pWind->DrawRectangle(j * config.brickWidth,
							i * config.brickHeight + config.toolBarHeight,
							j * config.brickWidth + config.brickWidth,
							i * config.brickHeight + config.brickHeight + config.toolBarHeight);
					}
				}
						break;
			}




		}

	}



	Center.x -= Xinc / 2;
	Center.y -= Yinc / 2;
	uprLft.x = Center.x;
	uprLft.y = Center.y;


}

ColliedInfo Ball::BallCollision(collidable*)
{
	return ColliedInfo();
}



void Ball::collisionAction()
{
}

point Ball::GetCenter()
{
	return Center;
}

void Ball::SetCenter(point P)
{
	this->Center = P;
}

int Ball::getRadius()
{
	return this->rad;
}

int Ball::getXinc()
{
	return this->Xinc;
}

int Ball::getYinc()
{
	return this->Yinc;
}

void Ball::SetXinc(int x)
{
	this->Xinc = x;
}

void Ball::SetYinc(int y)
{
	this->Yinc = y;
}

int Ball::GetCenterX()
{
	return this->Center.x;
}

