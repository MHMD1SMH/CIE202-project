#include "grid.h"
#include "game.h"
#include "gameConfig.h"

grid::grid(point r_uprleft, int wdth, int hght, game* pG):
	drawable(r_uprleft, wdth, hght, pG)
{

	rows = height / config.brickHeight;
	cols = width / config.brickWidth;

	brickMatrix = new brick ** [rows];
	for (int i = 0; i < rows; i++)
		brickMatrix[i] = new brick * [cols];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			brickMatrix[i][j] = nullptr;
}

grid::~grid()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (brickMatrix[i][j])
				delete brickMatrix[i][j];	//delete all allocated bricks

	for (int i = 0; i < rows; i++)
		delete brickMatrix[i];

	delete brickMatrix;

}

brick*** grid::GetBrick()
{
	return brickMatrix;
}

void grid::draw() const
{
	window* pWind = pGame->getWind();
	//draw lines showing the grid
	pWind->SetPen(config.gridLinesColor,1);

	//draw horizontal lines
	for (int i = 0; i < rows; i++) {
		int y = uprLft.y + (i + 1) * config.brickHeight;
		pWind->DrawLine(0, y, width, y);
	}
	//draw vertical lines
	for (int i = 0; i < cols; i++) {
		int x = (i + 1) * config.brickWidth;
		pWind->DrawLine(x, uprLft.y, x, uprLft.y+ rows* config.brickHeight);
	}

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (brickMatrix[i][j])
				brickMatrix[i][j]->draw();	//draw exisiting bricks


}

int grid::addBrick(BrickType brkType, point clickedPoint)
{
	//From the clicked point, find out the index (row,col) of the corrsponding cell in the grid
	int gridCellRowIndex = (clickedPoint.y-uprLft.y) / config.brickHeight;
	int gridCellColIndex = clickedPoint.x / config.brickWidth;
	//TODO:
	// 1- Check that the clickedPoint is within grid range (and return -1)
	// 2- Check that the clickedPoint doesnot overlap with an exisiting brick (return 0)
	if (clickedPoint.y > config.gridHeight + config.toolBarHeight ||
		clickedPoint.y < config.toolBarHeight)
	{
		return -1;
	}
	if (brickMatrix[gridCellRowIndex][gridCellColIndex])
	{
		return 0;
	}
	//Here we assume that the above checks are passed
	

	//Now, align the upper left corner of the new brick with the corner of the clicked grid cell
	point newBrickUpleft;
	newBrickUpleft.x = uprLft.x + gridCellColIndex * config.brickWidth;
	newBrickUpleft.y = uprLft.y+ gridCellRowIndex * config.brickHeight;

	switch (brkType)
	{
	case BRK_NRM:	//The new brick to add is Normal Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new normalBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;

		//TODO: 
		// handle more types
	case BRK_HRD:	//The new brick to add is Hard Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new hardBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	
	case BRK_RCK:	//The new brick to add is Rock Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new rockBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_UP:	//The new brick to add is Power Up Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new PowerUpBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_DOWN:	//The new brick to add is Power Up Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new PowerDownBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_BOM:	//The new brick to add is Power Up Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new BombBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_CONS:	//The new brick to add is Power Up Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new constructBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;

	}
	
	return 1;
}

int grid::deletBrick(int i, int j)
{
	if (brickMatrix[i][j]->BrickTybe() != BRK_RCK && config.destructPower == 1)
	{
		brickMatrix[i][j]->collisionAction();

		if (brickMatrix[i][j]->strength == 0) {

			delete brickMatrix[i][j];
			brickMatrix[i][j] = nullptr;

		}
	}
	else if (config.destructPower == 3)
	{
		brickMatrix[i][j]->collisionAction();
		delete brickMatrix[i][j];
		brickMatrix[i][j] = nullptr;
	}
	return 0;
}

int grid::Delete(point clickedPoint)
{
	window* pWind = pGame->getWind();
	//From the clicked point, find out the index (row,col) of the corrsponding cell in the grid
	int gridCellRowIndex = (clickedPoint.y - uprLft.y) / config.brickHeight;
	int gridCellColIndex = clickedPoint.x / config.brickWidth;
	//Now, align the upper left corner of the new brick with the corner of the clicked grid cell
	point BrickUpleft;
	BrickUpleft.x = uprLft.x + gridCellColIndex * config.brickWidth;
	BrickUpleft.y = uprLft.y + gridCellRowIndex * config.brickHeight;
	// Check that the clickedPoint is within grid range (and return -1)
	// Check that the clickedPoint doesnot overlap with an exisiting brick (return 0)
	if (clickedPoint.y > config.gridHeight + config.toolBarHeight ||
		clickedPoint.y < config.toolBarHeight)
	{
		return -1;
	}
	if (!brickMatrix[gridCellRowIndex][gridCellColIndex])
	{
		return 0;
	}
	// here we delete
	if (brickMatrix[gridCellRowIndex][gridCellColIndex])
	{
		
	delete brickMatrix[gridCellRowIndex][gridCellColIndex];
	brickMatrix[gridCellRowIndex][gridCellColIndex] = nullptr;
	pWind->SetPen(LAVENDER);
	pWind->SetBrush(LAVENDER);
	pWind->DrawRectangle(BrickUpleft.x,
		BrickUpleft.y,
		BrickUpleft.x + config.brickWidth,
		BrickUpleft.y + config.brickHeight);
	}
	return 1;
	
}

void grid::drawline()
{
	window* pWind = pGame->getWind();
	//draw lines showing the grid
	pWind->SetPen(config.gridLinesColor, 1);

	//draw horizontal lines
	for (int i = 0; i < rows; i++) {
		int y = uprLft.y + (i + 1) * config.brickHeight;
		pWind->DrawLine(0, y, width, y);
	}
	//draw vertical lines
	for (int i = 0; i < cols; i++) {
		int x = (i + 1) * config.brickWidth;
		pWind->DrawLine(x, uprLft.y, x, uprLft.y + rows * config.brickHeight);
	}

}


int grid::getRows()
{
	return rows;
}

int grid::getColumns()
{
	return cols;
}

