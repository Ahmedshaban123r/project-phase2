#include "game.h"
#include "gameConfig.h"



game::game()
{
	//Initialize playgrond parameters
	gameMode = MODE_DSIGN;

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
	//TODO: Add code to create and draw the paddle
	point paddleUpperleft;
	paddleUpperleft.x = (config.windWidth / 2) - (config.paddleWidth / 2);
	paddleUpperleft.y = config.paddleAreaHeight;
	padle = new paddle(paddleUpperleft, config.paddleWidth, config.paddleHeight, this);
	//padle->draw();

	//5- Create the ball
	//TODO: Add code to create and draw the ball
	point ballUpperleft;
	ballUpperleft.x = (config.windWidth / 2) - (config.balldiam / 2);
	ballUpperleft.y = config.paddleAreaHeight - config.balldiam;
	bal = new ball(ballUpperleft, config.ballrectX1 + config.balldiam, config.ballrectY1 + config.balldiam, this);
	//bal->draw();

	//6- Create and clear the status bar
	//point statusbarleft;
	//statusbarleft.x = 800;
	//statusbarleft.y =550;
	//stat = new status_bar(statusbarleft,config.windWidth , config.statusBarHeight, this);
	//stat->draw();



	//clearStatusBar();

}

game::~game()
{
	delete pWind;
	delete gameToolbar;
	delete bricksGrid;
	delete padle;
	delete bal;
	//delete stat;
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


void game::playStatusBar() const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), "SCORE:");
	pWind->DrawInteger(95, config.windHeight - (int)(0.85 * config.statusBarHeight), gameToolbar->getScore());
	pWind->DrawString((config.windWidth / 2) - 10, config.windHeight - (int)(0.85 * config.statusBarHeight), "LIVES:");
	pWind->DrawInteger((config.windWidth / 2) + 60, config.windHeight - (int)(0.85 * config.statusBarHeight), gameToolbar->getLives());
	pWind->DrawString(config.windWidth - 150, config.windHeight - (int)(0.85 * config.statusBarHeight), "TIME:");
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
	return bricksGrid;
}
void game::go() const
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;

	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - Brick Breaker (CIE202-project) - - - - - - - - - -");

	do
	{
		//padle->movement();

		printMessage("Ready...");
		getMouseClick(x, y);	//Get the coordinates of the user click
		//MODE m = this->getMode();
		if (gameMode == MODE_DSIGN)		//Game is in the Desgin mode
		{
			//[1] If user clicks on the Toolbar
			if (y >= 0 && y < config.toolBarHeight)
			{
				isExit = gameToolbar->handleClick(x, y);

			}

		}
		else if (gameMode == MODE_PLAY)
		{
			timer();
			padle->draw();
			bal->draw();
			pWind->FlushKeyQueue();
			keytype Q;
			char Cha;
			Q = pWind->WaitKeyPress(Cha);
			if (Q == ASCII && Cha == ' ') {
				do {
					config.j += 0.03;

					playStatusBar();
					updateTime(config.i, config.j);
					bal->Balllaunch();
					padle->movement();
					//gameToolbar->Timer();
					//pWind->DrawInteger(1075, config.toolBarHeight / 2, gameToolbar->getSeconds());
					//if (gameToolbar->getMinutes() != 0) {
					//	pWind->DrawInteger(1125, config.toolBarHeight / 2, gameToolbar->getMinutes());
					//}
					pWind->GetMouseClick(x, y);
					if (y > 0 && y <= config.toolBarHeight && x < config.iconWidth * 7) {
						gameToolbar->handleClick(x, y);
					}
				} while (isPlay);
			}
		}



	} while (!isExit);
}
MODE game::getMode() const
{
	return gameMode;
}

void game::setmode(MODE M)
{
	gameMode = M;

}

toolbar* game::getToolbar() const
{
	return gameToolbar;
}

void game::setIsplay(bool p)
{
	isPlay = p;
}

void game::setIspause(bool p)
{
	isPause = p;
}

void game::timer() const
{

	if (bal->get_power() != nullptr) {
		config.timer += 0.03;
	}
	if (config.timer >= 30) {
		bal->get_power() == nullptr;
		padle->get_power() == nullptr;
	}
}

paddle* game::getPaddle() const
{
	return padle;
}

ball* game::getBall() const
{
	return bal;
}

void game::updateTime(double i, double j) const
{

	string minutes[11] = { "10","09","08","07","06","05","04","03","02","01","00" };
	string seconds[60] = { "59","58","57","56","55","54","53","52","51","50",
						  "49","48","47","46","45","44","43","42","41","40",
						  "39","38","37","36","35","34","33","32","31","30",
						  "29","28","27","26","25","24","23","22","21","20",
						  "19","18","17","16","15","14","13","12","11","10",
						  "09","08","07","06","05","04","03","02","01","00",
	};
	if (seconds[int(j)] == "00") {
		config.i++;
		config.j = 0;
	}
	else {
		config.i = config.i;
	}
	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(config.windWidth - 75, config.windHeight - (int)(0.85 * config.statusBarHeight), minutes[int(i)] + ":" + seconds[int(j)]);

}