#include "game.h"
#include "gameConfig.h"
#include <iostream>


game::game()
{
	//Initialize playgrond parameters
	gameMode =new MODE (MODE_DSIGN);
	lives = new Live;
	score = new Score;
	
	

	//1 - Create the main window
	pWind = CreateWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//2 - create and draw the toolbar
	point toolbarUpperleft;
	toolbarUpperleft.x = 0;
	toolbarUpperleft.y = 0;

	gameToolbar = new toolbar(toolbarUpperleft,0,config.toolBarHeight, this);
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
}

void game::ChangeGameMode( int C)
{
	if (C == 0 )
	{
		*gameMode = MODE_DSIGN;
	}
	else if (C == 1 ) {
		 
		*gameMode = MODE_STOP;

	}
	else
	{
		*gameMode = MODE_PLAY;
	}
	
	// git hub test 2
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

void game::SetScore( int n)
{
	score->setScore(n);
}

int game::GetScore() const
{
	return score->getScore();
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

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	bricksGrid->draw();
	return bricksGrid;
}



////////////////////////////////////////////////////////////////////////
void game::go() const
{
	//This function reads the position where the user clicks to determine the desired operation

	bool Space_isPressed  = false;
	int x, y;
	bool isExit = false;
	char Key;
	keytype ktype;
	bool bDragging = false;
	

	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - Brick Breaker (CIE202-project) - - - - - - - - - -");
	
	do
	{
		
		printMessage("Ready...");
		
		getMouseClick(x, y);	//Get the coordinates of the user click
		
		if (*gameMode == MODE_DSIGN)		//Game is in the Desgin mode
		{
			//[1] If user clicks on the Toolbar
			if (y >= 0 && y < config.toolBarHeight)
			{
				isExit=gameToolbar->handleClick(x, y);

			}
		}
		
		 if (*gameMode == MODE_PLAY)
		{
			printMessage("You can play now  ==> Press space bar to start <==");
			pWind->FlushKeyQueue();
			ktype = pWind->WaitKeyPress(Key);
			if (Key == 32){
				Space_isPressed = true;
			}
				Time *time = new Time;
			while (Space_isPressed)
			{
				
				pWind->SetPen(LAVENDER);
				pWind->SetBrush(LAVENDER);
				pWind->DrawRectangle(0, config.paddleStartHeight, config.windWidth, config.windHeight - config.statusBarHeight);
				pWind->FlushKeyQueue();
				Paddle->draw();
				ballGame->draw(LAVENDER, pWind);

				getGrid();
				if (Space_isPressed) {
					ballGame->MoveBall(Paddle, bricksGrid->GetBrick(), pWind);
					ballGame->draw(RED, pWind);
				}

				
				Pause(10);
		    	pWind->FlushKeyQueue();
				
				ktype=pWind->GetKeyPress(Key);
				if (Key == 100) {
					Paddle->movePaddle(true);

					Paddle->draw();
				}
				if (Key == 97) {
					Paddle->movePaddle(false);
					Paddle->draw();
				}
				string messege = " Lives :" + to_string(lives->getLive()) +
					" | Score :" + to_string(score->getScore()) +
					" | Time : " + to_string(time->getinmin()) + ":" + to_string(time->getinsec());
				printMessage(messege);
				
				pWind->UpdateBuffer();
				
				pWind->GetMouseClick(x, y);
				if (x > (config.iconWidth * 4) && y >= 0 && y < config.toolBarHeight && x < config.iconWidth*8)
				{

				
					isExit = gameToolbar->handleClick(x, y);

				
					Space_isPressed = false;

				}
			}
			
					
			//pWind->SetBuffering(false);
		}
		 if (*gameMode == MODE_STOP)
		{
			
			string messege = " Lives :" + to_string(lives->getLive()) + " | Score :" + to_string(score->getScore()) + " | Time : ";
			printMessage(messege);
			//getMouseClick(x, y);
			if (y >= 0 && y < config.toolBarHeight && x > config.iconWidth*5)
			{
				isExit = gameToolbar->handleClick(x, y);
				
			}
		}
		
	} while (!isExit);
	
}
