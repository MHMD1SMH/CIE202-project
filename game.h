#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "Ball.h"
#include "toolbar.h"
#include "grid.h"
#include "Paddle.h"
#include "Score.h"
#include "Lives.h"
#include "Time.h"
#include "collectable.h"


//Main class that coordinates the game operation
class game
{
private:
	enum MODE	//Game mode
	{
		MODE_DSIGN,	//Desing mode (startup mode)
		MODE_STOP,	//STOP mode 

		MODE_PLAY,	//Playing mode
		MODE_END,	//End Game mode

	};
	Score* score;
	Live* lives;
	MODE* gameMode;
	Ball* ballGame;
	paddle* Paddle;
	window* pWind;	//Pointer to the CMU graphics window
	toolbar* gameToolbar;
	grid* bricksGrid;
	Time* timer;
	collectables* collectAbles;
	bool Space_isPressed;
public:
	game();
	~game();
	void ChangeGameMode(int C) const;
	int GetGameMode() ;
	void SetScore(int n);
	int GetScore() const;
	void addUpCollectable(point);
	void addDownCollectable(point);
	void increasePaddleSpeed();
	void increasePaddleWidth();
	void decreasePaddleSpeed();
	void decreasePaddleWidth();
	void reversePaddleDirection();


	clicktype getMouseClick(int& x, int& y) const;//Get coordinate where user clicks and returns click type (left/right)
	string getSrting() const;	 //Returns a string entered by the user


	window* CreateWind(int, int, int, int) const; //creates the game window


	void clearStatusBar() const;	//Clears the status bar


	void printMessage(string msg) const;	//Print a message on Status bar

	void go() const;

	window* getWind() const;		//returns a pointer to the graphics window

	paddle* getPaddle() const;
	grid* getGrid() const;
	Ball* getBall() const;
	brick*** getMatrix() const;
};

