#include "toolbar.h"
#include "game.h"
#include "grid.h"
#include "gameConfig.h"
#include<fstream>


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
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}

////////////////////////////////////////////////////  class iconAddHardBrick   //////////////////////////////////////////////
iconAddHardBrick::iconAddHardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{

}

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
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");
}

////////////////////////////////////////////////////  class iconAddRockBrick   //////////////////////////////////////////////
iconAddRockBrick::iconAddRockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{

}

void iconAddRockBrick::onClick()
{
	pGame->printMessage("Click on empty cells to add Normal Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid =+ pGame->getGrid();
		pGrid->addBrick(BRK_ROK, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");
}
////////////////////////////////////////////////////  class iconAddBombBrick   //////////////////////////////////////////////
iconAddBombBrick::iconAddBombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{

}

void iconAddBombBrick::onClick()
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
		pGrid->addBrick(BRK_BOM, clicked);
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
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	if (t == LEFT_CLICK) {
		pGame->~game();
	}
}
icondelete::icondelete(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame) {}
void icondelete::onClick()
{
	pGame->printMessage("Click on filled cells to remove Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{

		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->deleteBrick(clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}
////////////////////////////////////////////////////  class iconload   //////////////////////////////////////////////

iconload::iconload(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame){}
void iconload::onClick()
{
	pGame->printMessage("Loading File... ==> Right-Click to stop <==");
	ifstream loadfile;
	auto pGrid = pGame->getGrid();
	loadfile.open("Load.txt");
	if (loadfile.is_open())
	{

		pGrid->draw();

		// Load bricks from file
		int i, j, type;
		while (loadfile >> i >> j >> type)
		{
			// Add bricks to the grid
			point uplft;
			uplft.x = (j - 1) * config.brickWidth;
			uplft.y = (i - 1) * config.brickHeight;
			BrickType bt = BrickType(type);
			pGrid->addBrick(bt, uplft);
		}

		loadfile.close();
		pGame->printMessage("File Loaded Successfully.");
	}
	else
	{
		pGame->printMessage("Failed to open the file for loading.");
	}

}
////////////////////////////////////////////////////  class iconsave  //////////////////////////////////////////////

iconsave::iconsave(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame){}
void iconsave::onClick()
{
	pGame->printMessage("File Saved Successfully==> Right-Click to stop <==");
	ofstream savefile;
	auto pGrid = pGame->getGrid();
	savefile.open("save.txt");
	brick*** bm = pGrid->get_brickmatrix();
	int rows = pGrid->get_rows();
	int cols = pGrid->get_cols();
	int type;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (bm[i][j] != nullptr)
			{
				savefile << i + 1 << " ";
				savefile << j + 1 << " ";
				type = int(bm[i][j]->get_type());
				savefile << type << endl;
			}
		}
	}
	savefile.close();
	pGame->printMessage("");
}


iconplay::iconplay(point r_uprleft, int r_width, int r_height, game* r_pGame):
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{
}
void iconplay::onClick()
{
	pGame->setIspause(false);
	pGame->setIsplay(true);
	pGame->setmode(MODE_PLAY);

}

iconstop::iconstop(point r_uprleft, int r_width, int r_height, game* r_pGame):
toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{

}
void iconstop::onClick()
{
	pGame->setIspause(true);
	pGame->setIsplay(false);
	pGame->setmode(MODE_DSIGN);
	pGame->getPaddle()->~paddle();
	pGame->getBall()->~ball();
	pGame->getGrid()->draw();
}

iconpause::iconpause(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{

}
void iconpause::onClick()
{
	pGame->setIspause(true);
	pGame->setIsplay(false);
}

////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
toolbar::toolbar(point r_uprleft, int wdth, int hght, game* pG) :
	drawable(r_uprleft, wdth, hght, pG)
{
	point p;
	p.x = 0;
	p.y = 0;
	
		height = hght;
		pGame = pG;

		//First prepare List of images for each icon
		//To control the order of these images in the menu, reoder them in enum ICONS above	
		iconsImages[ICON_ADD_NORM] = "images\\ToolbarIcons\\NormalBrickIcon.jpg";
		iconsImages[ICON_ADD_HARD] = "images\\ToolbarIcons\\hardBrickIcon.jpg";
		iconsImages[ICON_ADD_ROCK] = "images\\ToolbarIcons\\rockBrickIcon.jpg";
		iconsImages[ICON_ADD_BOMB] = "images\\ToolbarIcons\\bombbrickIcon.png";
		iconsImages[ICON_ADD_POWER] = "images\\ToolbarIcons\\PowerBrickIcon.jpg";
		iconsImages[ICON_DEL_BRICK] = "images\\ToolbarIcons\\DeleteIcon.jpg";
		iconsImages[ICON_LOAD] = "images\\ToolbarIcons\\LoadIcon.jpg";
		iconsImages[ICON_SAVE] = "images\\ToolbarIcons\\SaveIcon.jpg";
		iconsImages[ICON_EXIT] = "images\\ToolbarIcons\\ExitIcon.jpg";
		iconsImages[ICON_PLAY] = "images\\ToolbarIcons\\PlayIcon.jpg";
		iconsImages[ICON_STOP]= "images\\ToolbarIcons\\StopIcon.jpg";
		iconsImages[ICON_PAUSE] = "images\\ToolbarIcons\\PauseIcon.jpg";
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
		iconsList[ICON_ADD_POWER] = new iconAddBombBrick(p, config.iconWidth, height, pGame);
		p.x += config.iconWidth;
		iconsList[ICON_DEL_BRICK] = new icondelete(p, config.iconWidth, height, pGame);
		p.x += config.iconWidth;
		iconsList[ICON_LOAD] = new iconload(p, config.iconWidth, height, pGame);
		p.x += config.iconWidth;
		iconsList[ICON_SAVE] = new iconsave(p, config.iconWidth, height, pGame);
		p.x += config.iconWidth;
		iconsList[ICON_EXIT] = new iconExit(p, config.iconWidth, height, pGame);
		p.x += config.iconWidth;
		iconsList[ICON_PLAY] = new iconplay(p, config.iconWidth, height, pGame);
		p.x += config.iconWidth;
		iconsList[ICON_STOP] = new iconstop(p, config.iconWidth, height, pGame);
		p.x += config.iconWidth;
		iconsList[ICON_PAUSE] = new iconpause(p, config.iconWidth, height, pGame);
		
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
int toolbar::getLives()
{
	return Lives;
}

int toolbar::getScore()
{
	return score;
}

int toolbar::updateLives()
{
	Lives -= 1;
	return Lives;
}








