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
brick*** grid::get_brickmatrix()
{
	return 	brickMatrix;		//2D array of brick pointers
	
}
int grid::get_rows()
{
	return rows;
}

int grid::get_cols()
{
	return cols;
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
	if (clickedPoint.x >= 0 && clickedPoint.x <= config.windWidth && clickedPoint.y >= 50 && clickedPoint.y <= config.toolBarHeight + config.gridHeight)
	{

		//From the clicked point, find out the index (row,col) of the corrsponding cell in the grid
		int gridCellRowIndex = (clickedPoint.y - uprLft.y) / config.brickHeight;
		int gridCellColIndex = clickedPoint.x / config.brickWidth;

		//Now, align the upper left corner of the new brick with the corner of the clicked grid cell
		point newBrickUpleft;
		newBrickUpleft.x = uprLft.x + gridCellColIndex * config.brickWidth;
		newBrickUpleft.y = uprLft.y + gridCellRowIndex * config.brickHeight;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (brickMatrix[i][j]->getpoint().x == newBrickUpleft.x && brickMatrix[i][j]->getpoint().y == newBrickUpleft.y)
					return 0;
				else
					switch (brkType)
					{
					case BRK_NRM:	//The new brick to add is Normal Brick
						brickMatrix[gridCellRowIndex][gridCellColIndex] = new normalBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
						break;

					case BRK_HRD:	//The new brick to add is hard Brick
						brickMatrix[gridCellRowIndex][gridCellColIndex] = new hardBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
						break;
					case BRK_ROK:	//The new brick to add is rock Brick
						brickMatrix[gridCellRowIndex][gridCellColIndex] = new rockBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
						break;
					case BRK_BOM:	//The new brick to add is rock Brick
						brickMatrix[gridCellRowIndex][gridCellColIndex] = new bombBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
						break;
					case BRK_POW:	//The new brick to add is rock Brick
						brickMatrix[gridCellRowIndex][gridCellColIndex] = new powerBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
						break;
						//TODO: 
						// handle more types
					}
				return 1;

			}
		}
	}
	else
		return 0;
}

void grid::deleteBrick(point clickedPoint)
{
	int gridCellRowIndex = (clickedPoint.y - uprLft.y) / config.brickHeight;
	int gridCellColIndex = clickedPoint.x / config.brickWidth;
	point newBrickPos;
	newBrickPos.x = uprLft.x + gridCellColIndex * config.brickWidth;
	newBrickPos.y = uprLft.y + gridCellRowIndex * config.brickHeight;


	if (brickMatrix[gridCellRowIndex][gridCellColIndex] != nullptr) {
		delete brickMatrix[gridCellRowIndex][gridCellColIndex];
		brickMatrix[gridCellRowIndex][gridCellColIndex] = nullptr;
		pGame->getWind()->SetPen(LAVENDER, 1);
		pGame->getWind()->SetBrush(config.bkGrndColor);
		pGame->getWind()->DrawRectangle(newBrickPos.x, newBrickPos.y, newBrickPos.x + config.brickWidth, newBrickPos.y + config.brickHeight, FILLED);
	}
}

void grid::destroy_brick(int R, int C)
{
	int k=0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (brickMatrix[i][j] == nullptr)
				k++;
		}
		if (k != cols * rows)
		{


			if (brickMatrix[R][C]->get_type() == BRK_BOM)
			{
				pWind = pGame->getWind();
				pGame->getWind()->SetPen(LAVENDER, 1);
				pGame->getWind()->SetBrush(config.bkGrndColor);
				pWind->DrawRectangle(brickMatrix[R][C]->getpoint().x, brickMatrix[R][C]->getpoint().y, brickMatrix[R][C]->getpoint().x + config.brickWidth, brickMatrix[R][C]->getpoint().y + config.brickHeight);
				delete brickMatrix[R][C];
				brickMatrix[R][C] = nullptr;
				if (R == 1)
				{
					grid::destroy_brick(R + 1, C);
					grid::destroy_brick(R, C - 1);
					grid::destroy_brick(R, C + 1);
				}
				else if (R == rows)
				{
					grid::destroy_brick(R - 1, C);
					grid::destroy_brick(R, C - 1);
					grid::destroy_brick(R, C + 1);
				}
				else if (C == 1)
				{
					grid::destroy_brick(R - 1, C);
					grid::destroy_brick(R + 1, C);
					grid::destroy_brick(R, C + 1);
				}
				else if (C == cols)
				{
					grid::destroy_brick(R - 1, C);
					grid::destroy_brick(R + 1, C);
					grid::destroy_brick(R, C - 1);
				}
				else {
					grid::destroy_brick(R - 1, C);
					grid::destroy_brick(R + 1, C);
					grid::destroy_brick(R, C - 1);
					grid::destroy_brick(R, C + 1);
				}
			}
			else
			{
				pWind = pGame->getWind();
				pGame->getWind()->SetPen(LAVENDER, 1);
				pGame->getWind()->SetBrush(config.bkGrndColor);
				pWind->DrawRectangle(brickMatrix[R][C]->getpoint().x, brickMatrix[R][C]->getpoint().y, brickMatrix[R][C]->getpoint().x + config.brickWidth, brickMatrix[R][C]->getpoint().y + config.brickHeight);
				delete brickMatrix[R][C];
				brickMatrix[R][C] = nullptr;
			}
		}
}
}


