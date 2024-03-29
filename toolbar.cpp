#include "toolbar.h"
#include "game.h"
#include "grid.h"
#include "gameConfig.h"
#include <iostream>
#include "Bricks.h"
//#include <fstream>
////////////////////////////////////////////////////  class toolbarIcon   ////////////////////////////////////////////////////
toolbarIcon::toolbarIcon(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	drawable(r_uprleft, r_width, r_height, r_pGame)
{}




////////////////////////////////////////////////////  class iconAddNormalBrick   //////////////////////////////////////////////
iconAddNormalBrick::iconAddNormalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddNormalBrick::onClick()
{

	pGame->printMessage("Click on empty cells to add Normal Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_NRM, clicked);
		config.totalScore += 1;
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}
////////////////////////////////////////////////////  class iconAddPowUpBrick   //////////////////////////////////////////////
iconAddPowUpBrick::iconAddPowUpBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddPowUpBrick::onClick()
{

	pGame->printMessage("Click on empty cells to add Power Up Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_UP, clicked);
		config.totalScore += 1;
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}////////////////////////////////////////////////////  class iconAddPowDwnBrick   //////////////////////////////////////////////
iconAddPowDwnBrick::iconAddPowDwnBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddPowDwnBrick::onClick()
{

	pGame->printMessage("Click on empty cells to add Power Down Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_DOWN, clicked);
		config.totalScore += 1;
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}

////////////////////////////////////////////////////  class iconAddHardBrick   //////////////////////////////////////////////
iconAddHardBrick::iconAddHardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddHardBrick::onClick()
{

	pGame->printMessage("Click on empty cells to add Hard Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_HRD, clicked);
		pGrid->draw();
		config.totalScore += 3;
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}

////////////////////////////////////////////////////  class iconAddRockBrick   //////////////////////////////////////////////
iconAddRockBrick::iconAddRockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddRockBrick::onClick()
{

	pGame->printMessage("Click on empty cells to add Rock Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_RCK, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}////////////////////////////////////////////////////  class iconAddConsBrick   //////////////////////////////////////////////
iconAddConsBrick::iconAddConsBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddConsBrick::onClick()
{

	pGame->printMessage("Click on empty cells to add constructive Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_CONS, clicked);
		config.totalScore += 1;
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}
////////////////////////////////////////////////////  class iconAddBombBrick   //////////////////////////////////////////////
iconAddBombBrick::iconAddBombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddBombBrick::onClick()
{

	pGame->printMessage("Click on empty cells to add Bomb Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_BOM, clicked);
		config.totalScore += 4;
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}
////////////////////////////////////////////////////  class iconErase   //////////////////////////////////////////////
iconErase::iconErase(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconErase::onClick()
{

	pGame->printMessage("Click on full cells to Delete Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->Delete(clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}


////////////////////////////////////////////////////  class iconExit   //////////////////////////////////////////////
iconExit::iconExit(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconExit::onClick()
{
	//TO DO: add code for cleanup and game exit here

}
////////////////////////////////////////////////////  class iconSave   //////////////////////////////////////////////
iconSave::iconSave(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{

}

void iconSave::onClick()
{
	//TO DO: add code for cleanup and game exit here
	outFile.open("gameDesign.txt");
	for (int i = 0; i < pGame->getGrid()->getRows(); i++)
	{
		for (int j = 0; j < pGame->getGrid()->getColumns(); j++)
		{
			if (pGame->getMatrix()[i][j])
			{
				outFile << i << " " << j << " " << pGame->getMatrix()[i][j]->BrickTybe() << "\n";
			}
		}
	}
	//outFile << 1 << " " << 0 << " " << 0;

	outFile.close();
}

////////////////////////////////////////////////////  class iconLoad   //////////////////////////////////////////////
iconLoad::iconLoad(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{
	c = 0;


}

void iconLoad::onClick()
{

	inFile.open("gameDesign.txt");
	//pGame->printMessage("Loading");
	//TO DO: add code for cleanup and game exit here
	BrickType bricktybe ;
	int type = 0;
	point xy;
	xy.x = 0;
	xy.y = 0;
	while (inFile)
	{

		if (c == 0)
		{

			(inFile) >> xy.y;

			c += 1;
		}
		else if (c == 1) {

			inFile >> xy.x;

			c += 1;
		}
		else if (c == 2)
		{

			inFile >> type;
			bricktybe = BrickType(type);
			c += 1;
		}
		if (c == 3)
		{
			xy.y = config.toolBarHeight + xy.y * config.brickHeight;
			xy.x = xy.x * config.brickWidth;
			pGame->getGrid()->addBrick(bricktybe, xy);
			if (bricktybe == BRK_HRD)
			{
				config.totalScore+=3;
			}
			else if (bricktybe != BRK_RCK)
			{
				config.totalScore+=1;
			}
			c = 0;
		}

	}
	inFile.close();
	pGame->getGrid()->draw();
}


////////////////////////////////////////////////////  class iconPlay   //////////////////////////////////////////////
iconPlay::iconPlay(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconPlay::onClick()
{



	pGame->ChangeGameMode(2);

}

////////////////////////////////////////////////////  class iconPause   //////////////////////////////////////////////
iconPause::iconPause(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconPause::onClick()
{

	//TO DO: add code for cleanup and game exit here
	pGame->ChangeGameMode(1);


}

////////////////////////////////////////////////////  class iconContinue   //////////////////////////////////////////////
iconContinue::iconContinue(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconContinue::onClick()
{
	//TO DO: add code for cleanup and game exit here
	pGame->ChangeGameMode(2);

}

////////////////////////////////////////////////////  class iconStop   //////////////////////////////////////////////
iconStop::iconStop(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconStop::onClick()
{
	//TO DO: add code for cleanup and game exit here
	pGame->ChangeGameMode(0);
	pGame->getBall()->draw(LAVENDER);
	pGame->getPaddle()->draw(LAVENDER);
	pGame->getGrid()->drawline();

}


////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
toolbar::toolbar(point r_uprleft, int wdth, int hght, game* pG) :
	drawable(r_uprleft, wdth, hght, pG)
{

	height = hght;
	pGame = pG;

	//First prepare List of images for each icon
	//To control the order of these images in the menu, reoder them in enum ICONS above	
	iconsImages[ICON_ADD_NORM] = "images\\ToolbarIcons\\NormalBrickIcon.jpg";
	iconsImages[ICON_ADD_HARD] = "images\\ToolbarIcons\\HardBrickIcon.jpg";
	iconsImages[ICON_ADD_ROCK] = "images\\ToolbarIcons\\RockBrickIcon.jpg";
	iconsImages[ICON_ADD_POWUP] = "images\\ToolbarIcons\\PowerUpBrickIcon.jpg";
	iconsImages[ICON_ADD_POWDWN] = "images\\ToolbarIcons\\PowerDownBrickIcon.jpg";
	iconsImages[ICON_ADD_BOMB] = "images\\ToolbarIcons\\BombBrickIcon.jpg";
	iconsImages[ICON_ADD_CONS] = "images\\ToolbarIcons\\ConstructBrickIcon.jpg";
	iconsImages[ICON_ERASE] = "images\\ToolbarIcons\\EraseIcon.jpg";
	iconsImages[ICON_SAVE] = "images\\ToolbarIcons\\SaveIcon.jpg";
	iconsImages[ICON_LOAD] = "images\\ToolbarIcons\\LoadIcon.jpg";
	iconsImages[ICON_PLAY] = "images\\ToolbarIcons\\PlayIcon.jpg";
	iconsImages[ICON_PAUSE] = "images\\ToolbarIcons\\BauseIcon.jpg";
	iconsImages[ICON_CONTINUE] = "images\\ToolbarIcons\\ContinueIcon.jpg";
	iconsImages[ICON_STOP] = "images\\ToolbarIcons\\StopIcon.jpg";
	iconsImages[ICON_EXIT] = "images\\ToolbarIcons\\ExitIcon.jpg";

	point p;
	p.x = 0;
	p.y = 0;

	iconsList = new toolbarIcon * [ICON_COUNT];

	//For each icon in the tool bar
	//	1- Create an object setting its upper left corner, width and height
	iconsList[ICON_ADD_NORM] = new iconAddNormalBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_HARD] = new iconAddHardBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_ROCK] = new iconAddRockBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_BOMB] = new iconAddBombBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_CONS] = new iconAddConsBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_POWUP] = new iconAddPowUpBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_POWDWN] = new iconAddPowDwnBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ERASE] = new iconErase(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_SAVE] = new iconSave(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_LOAD] = new iconLoad(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_PLAY] = new iconPlay(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_PAUSE] = new iconPause(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_CONTINUE] = new iconContinue(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_STOP] = new iconStop(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_EXIT] = new iconExit(p, config.iconWidth, height, pGame);

	//	2-Set its image (from the above images list)
	for (int i = 0; i < ICON_COUNT; i++)
	{
		iconsList[i]->setImageName(iconsImages[i]);

	}
}

toolbar::~toolbar()
{
	for (int i = 0; i < ICON_COUNT; i++)
		delete iconsList[i];
	delete iconsList;
}

void toolbar::draw() const
{
	for (int i = 0; i < ICON_COUNT; i++)
		iconsList[i]->draw();
	window* pWind = pGame->getWind();
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, height, pWind->GetWidth(), height);

}

//handles clicks on toolbar icons, returns true if exit is clicked
bool toolbar::handleClick(int x, int y)
{
	if (x > ICON_COUNT * config.iconWidth)	//click outside toolbar boundaries
		return false;


	//Check whick icon was clicked
	//==> This assumes that menu icons are lined up horizontally <==
	//Divide x coord of the point clicked by the icon width (int division)
	//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

	int clickedIconIndex = (x / config.iconWidth);

	iconsList[clickedIconIndex]->onClick();	//execute onClick action of clicled icon

	if (clickedIconIndex == ICON_EXIT) return true;

	return false;


}


