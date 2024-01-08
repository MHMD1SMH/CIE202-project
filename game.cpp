#include "game.h"
#include "gameConfig.h"
#include <iostream>


game::game()
{

	//Initialize playgrond parameters
	gameMode = new MODE(MODE_DSIGN);
	lives = new Live;
	score = new Score;
	timer = new Time(false);

	collectAbles = new collectables();

	//1 - Create the main window
	pWind = CreateWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//2 - create and draw the toolbar
	point toolbarUpperleft;
	toolbarUpperleft.x = 0;
	toolbarUpperleft.y = 0;

	gameToolbar = new toolbar(toolbarUpperleft, 0, config.toolBarHeight, this);
	gameToolbar->draw();

	//3 - create and draw the grid
	point gridUpperleft;
	gridUpperleft.x = 0;
	gridUpperleft.y = config.toolBarHeight;
	bricksGrid = new grid(gridUpperleft, config.windWidth, config.gridHeight, this);
	bricksGrid->draw();

	//4- Create the Paddle
	//TODO: Add 
	Paddle = new paddle(config.paddleWidth, config.paddleHeigth, this);

	//5- Create the ball
	//TODO: Add code to create and draw the ball

	point ballUprLeft;
	ballUprLeft.x = 600;
	ballUprLeft.y = 450;
	int rad = 15;
	ballGame = new Ball(ballUprLeft, rad, rad, this);
	//6- Create and clear the status bar
	clearStatusBar();

}

game::~game()
{
	delete ballGame;
	delete Paddle;
	delete pWind;
	delete gameToolbar;
	delete bricksGrid;
	delete timer;
	delete collectAbles;


}

void game::ChangeGameMode(int C) const
{
	if (C == 0)
	{
		*gameMode = MODE_DSIGN;
	}
	else if (C == 1) {

		*gameMode = MODE_STOP;

	}
	else if (C == 2)
	{
		*gameMode = MODE_PLAY;
	}
	else if (C == 3)
	{
		*gameMode = MODE_END;
	}


	// git hub test 3

}

int game::GetGameMode()
{
	if (*gameMode == MODE_DSIGN)
	{
		return 0;
	}
	else
		return 1;
}

void game::SetScore(int n)
{
	score->setScore(n);
}

int game::GetScore() const
{
	return score->getScore();
}

void game::increasePaddleSpeed()
{
	Paddle->increasePaddleSpeed();
}

void game::increasePaddleWidth()
{

	Paddle->increasePaddleWidth();
}

void game::decreasePaddleSpeed()
{
	Paddle->decreasePaddleSpeed();
}

void game::decreasePaddleWidth()
{
	Paddle->decreasePaddleWidth();
}

void game::reversePaddleDirection()
{
	Paddle->reversePaddleDirection();
}


clicktype game::getMouseClick(int& x, int& y) const
{
	return pWind->WaitMouseClick(x, y);	//Wait for mouse click
}
//////////////////////////////////////////////////////////////////////////////////////////
window* game::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(config.bkGrndColor);
	pW->SetPen(config.bkGrndColor, 1);
	pW->DrawRectangle(0, 0, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////

void game::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
}






window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}



string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

paddle* game::getPaddle() const
{
	return Paddle;
}

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	//bricksGrid->draw();
	return bricksGrid;
}

void game::setBallColor(color C)
{
	ballColor = C;
}

Ball* game::getBall() const
{
	return ballGame;
}

brick*** game::getMatrix() const
{
	return bricksGrid->GetBrick();
}

Time* game::getTime() const
{
	return timer;
}
void game::setLive()
{
	lives->setLive();
}

brick* game::getBrick(int i, int j)
{
	return getGrid()->GetBrick()[i][j];
}




void game::addUpCollectable(point upr_lft)
{
	collectAbles->addUpCollectable(upr_lft, this);
}

void game::addDownCollectable(point upr_lft)
{
	collectAbles->addDownCollectable(upr_lft, this);
}


////////////////////////////////////////////////////////////////////////
void game::go() const
{
	int x, y;
	bool isExit = false;
	char Key;
	keytype ktype;
	bool bDragging = false;


	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - Brick Breaker (CIE202-project) - - - - - - - - - -");

	do
	{


		if ((*gameMode == MODE_PLAY || *gameMode == MODE_STOP)) 
		{
			string messege = " Lives :" + to_string(lives->getLive()) +
				" | Score :" + to_string(score->getScore()) +
				" | Time : " + timer->getinmin() + ":" + timer->getinsec();
			printMessage(messege);
		}
		else
		{
			printMessage("Ready...");

			getMouseClick(x, y);	//Get the coordinates of the user click

		}


		if (*gameMode == MODE_DSIGN)		//Game is in the Desgin mode
		{

			//[1] If user clicks on the Toolbar
			if (y >= 0 && y < config.toolBarHeight && (x < 11 * config.iconWidth || x >13 * config.iconWidth))
			{
				isExit = gameToolbar->handleClick(x, y);

			}

		}

		if (*gameMode == MODE_PLAY)
		{

			bool Space_isPressed = false;
			timer->setInit(true);
			printMessage("You can play now  ==> Press space bar to start <==");
			pWind->FlushKeyQueue();
			ktype = pWind->WaitKeyPress(Key);
			if (Key == 32) {
				Space_isPressed = true;
			}
			timer->setContinue();
			while (Space_isPressed)
			{

				pWind->FlushKeyQueue();

				getGrid()->drawline();
				
				pWind->UpdateBuffer();

				if (score->getScore() == config.totalScore)
				{
					*gameMode = MODE_END;
					pWind->SetPen(LAVENDER);
					pWind->SetBrush(LAVENDER);
					pWind->DrawRectangle(0, config.paddleStartHeight,
						config.windWidth, config.windHeight - config.statusBarHeight);
					Space_isPressed = false;
					break;

				}

				collectAbles->moveCollectables(Paddle, pWind);
				ballGame->draw(LAVENDER);
				ballGame->MoveBall();
				ballGame->draw(ballColor);



				Pause(5);
				pWind->FlushKeyQueue();
				ktype = pWind->GetKeyPress(Key);
				if (ballGame->getStuck() && Key == 32)
				{
					ballGame->setStuck(0);
				}
				pWind->SetPen(LAVENDER);
				pWind->SetBrush(LAVENDER);
				pWind->DrawRectangle(0, config.paddleStartHeight, config.windWidth, config.paddleStartHeight + config.paddleHeigth);
				if (Key == 100) {
					Paddle->movePaddle(true);


				}
				else if (Key == 97) {
					Paddle->movePaddle(false);

				}
				Paddle->draw(BLACK);

				string messege = " Lives :" + to_string(lives->getLive()) +
					" | Score :" + to_string(score->getScore()) +
					" | Time : " + timer->getinmin() + ":" + timer->getinsec();
				printMessage(messege);


				pWind->GetMouseClick(x, y);
				if (x > (config.iconWidth * 11) && y >= 0 && y < config.toolBarHeight && x < config.iconWidth * 16)
				{


					isExit = gameToolbar->handleClick(x, y);


					Space_isPressed = false;

				}
				if (ballGame->GetCenter().y > 480 + config.paddleHeigth)
				{
					ballGame->Reset();
					Paddle->Reset();
					lives->setLive();
					pWind->SetPen(LAVENDER);
					pWind->SetBrush(LAVENDER);
					pWind->DrawRectangle(0, config.paddleStartHeight,
						config.windWidth, config.windHeight - config.statusBarHeight);
					if (lives->getLive() > 0)
					{
						Paddle->draw(BLACK);

					}
					else
					{
						*gameMode = MODE_END;
					}




					Space_isPressed = false;
				}


			}

			timer->setInit(false);


		}
		if (*gameMode == MODE_STOP)
		{


			getMouseClick(x, y);
			if (y >= 0 && y < config.toolBarHeight && x > config.iconWidth * 12)
			{
				isExit = gameToolbar->handleClick(x, y);

			}

		}
		if (*gameMode == MODE_END)
		{
			if (lives->getLive() == 0)
			{
				point del;
				del.x = 0;
				del.y = 0;
				for (int i = 0; i < (config.gridHeight / config.brickHeight); i++) {

					for (int j = 0; j < (config.windWidth / config.brickWidth); j++)
					{
						if (getMatrix()[i][j]) {
							del.y = (i * config.brickHeight + config.toolBarHeight);
							del.x = j * config.brickWidth;
							getGrid()->Delete(del);

						}
					}

				}
				getGrid()->draw();
				string messege = "Game Over.  | Final Score :" + to_string(score->getScore());
				pWind->SetPen(RED, 50);
				pWind->SetFont(35, BOLD, BY_NAME, "Arial");
				pWind->DrawString(400, config.paddleStartHeight - 100, messege);
				clearStatusBar();

			}
			else if (score->getScore() == config.totalScore)
			{
				string messege;
				if (config.totalScore)
				{
					messege = "You Won  | Final Score :" + to_string(score->getScore());
				}
				else
				{
					messege = "Please, Add bricks to start";
				}
				pWind->SetPen(LIGHTSEAGREEN, 50);
				pWind->SetFont(35, BOLD, BY_NAME, "Arial");
				pWind->DrawString(400, config.paddleStartHeight - 100, messege);
				clearStatusBar();

			}
			timer->Reset();
			score->Reset();
			lives->Reset();

			getMouseClick(x, y);
			pWind->SetPen(LAVENDER);
			pWind->SetBrush(LAVENDER);
			pWind->DrawRectangle(0, config.toolBarHeight + config.gridHeight,
				config.windWidth, config.windHeight - config.statusBarHeight);
			ballGame->draw(LAVENDER);
			getGrid();
			ballGame->Reset();
			config.totalScore = 0;
			*gameMode = MODE_DSIGN;
		}

		pWind->SetBuffering(false);
	} while (!isExit);
}