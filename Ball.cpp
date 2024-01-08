#include "Ball.h"
#include "game.h"

Ball::Ball(point upr, game* p) :
	collidable(upr, 10, 10, p)
{
}

Ball::Ball(point ballUprLeft, int rad, int Hrad, game* r_pGame )
	:collidable(ballUprLeft, rad, Hrad, r_pGame)
{
	this->Center = ballUprLeft;
	this->rad = rad;
	Xinc = 0, Yinc = rad;
	isStuck = false;

}
void Ball::draw(color C) {
	//  bool bDragging = false;
	window* pWind;
	pWind = pGame->getWind();
	Color = C;
	pWind->SetPen(Color);
	pWind->SetBrush(Color);
	pWind->DrawCircle(Center.x, Center.y, rad);

}


void Ball::MoveBall()
{
	/// if ball went lower than the paddle
	//if (Center.y >= 490) {

	//	Center.y = 440;
	//	Center.x = config.windWidth / 2;

	//}

	collisionAction();


	if (!isStuck)
	{
		Center.x -= Xinc / 2;
		Center.y -= Yinc / 2;
		uprLft.x = Center.x;
		uprLft.y = Center.y;
	}
	else
	{
		Center.x = pGame->getPaddle()->getuprLeft().x + config.paddleWidth / 2;
		Center.y = config.paddleStartHeight - this->rad;
		uprLft.x = Center.x;
		uprLft.y = Center.y;
	}



}

ColliedInfo Ball::BallCollision(collidable*)
{
	return ColliedInfo();
}



void Ball::collisionAction()
{
	if ((Center.x <= rad) || (Center.x >= config.windWidth - rad) ||
		(isCollided(pGame->getPaddle(), this).isCollided && ((isCollided(pGame->getPaddle(), this).side == RIGHT) ||
			(isCollided(pGame->getPaddle(), this).side == LEFT)))) {
		if (isCollided(pGame->getPaddle(), this).isCollided) {
			if (Xinc < 0) {
				Xinc = -rad;
				Center.x -= 7.5;
			}
			else {
				Xinc = rad;
				Center.x += 7.5;

			}
			if (Yinc < 0) {
				Yinc = -rad;

			}
			else
			{
				Yinc = rad;


			}
		}
		else {
			Xinc = -Xinc;
		}
	}
	else if ((Center.y <= rad + config.toolBarHeight + 7) || (Center.y >= config.windHeight - rad - config.statusBarHeight - 4) ||
		(isCollided(pGame->getPaddle(), this).isCollided && ((isCollided(pGame->getPaddle(), this).side == UPPER) ||
			(isCollided(pGame->getPaddle(), this).side == LOWER)))) {
		if (isCollided(pGame->getPaddle(), this).isCollided) {
			if (Xinc < 0) {
				Xinc = -rad;

			}
			else {
				Xinc = rad;

			}

			if (Yinc < 0) {
				Yinc = -rad;
				Center.y -= 7.5;
			}
			else
			{
				Yinc = rad;
				Center.y += 7.5;

			}

			Yinc = -Yinc * abs(sin(DeflectedAngle(pGame->getPaddle(), this) * (3.14 / 180)));
			Xinc = Xinc * abs(cos(DeflectedAngle(pGame->getPaddle(), this) * (3.14 / 180)));

		}
		else {
			Yinc = -Yinc;
		}
	}
	for (int i = 0; i < (config.gridHeight / config.brickHeight); i++) {

		for (int j = 0; j < (config.windWidth / config.brickWidth); j++)
		{
			if (pGame->getMatrix()[i][j] && isCollided(pGame->getMatrix()[i][j], this).isCollided &&
				(isCollided(pGame->getMatrix()[i][j], this).side == LOWER ||
					isCollided(pGame->getMatrix()[i][j], this).side == UPPER)) {
				Yinc = -Yinc;
				/*if (Yinc > 0) {
					Center.y -= 7.5;
				}
				else
				{
					Center.y += 7.5;
				}*/


				pGame->getGrid()->deletBrick(i, j);
				break;
			}
			else if (pGame->getMatrix()[i][j] && isCollided(pGame->getMatrix()[i][j], this).isCollided &&
				(isCollided(pGame->getMatrix()[i][j], this).side == LEFT ||
					isCollided(pGame->getMatrix()[i][j], this).side == RIGHT)) {
				Xinc = -Xinc;
				/*if (Xinc > 0)
					Center.x -= 7.5;
				else
					Center.x += 7.5;*/

				pGame->getGrid()->deletBrick(i, j);

				break;
			}
		}

	}

}


point Ball::GetCenter()
{
	return Center;
}




void Ball::SetCenter(point p)
{
	Center;
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

void Ball::Reset()
{
	Center.x = 600;
	Center.y = 450;
	Xinc = 0;
	Yinc = -rad;
}

void Ball::setStuck(bool Stuck)
{
	isStuck = Stuck;
}

bool Ball::getStuck() const
{
	return isStuck;
}


