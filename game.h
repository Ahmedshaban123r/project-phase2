#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include "grid.h"
#include "status_bar.h"
#include "paddle.h"
#include "ball.h"
#include <chrono>


//#include "status_bar.h"
enum MODE	//Game mode
{
	MODE_DSIGN,	//Desing mode (startup mode)
	MODE_PLAY	//Playing mode
};



//Main class that coordinates the game operation
class game
{


	MODE gameMode;

	/// Add more members if needed


	bool isPlay;
	bool isPause;
	window* pWind;	//Pointer to the CMU graphics window
	toolbar* gameToolbar;
	grid* bricksGrid;
	/*status_bar* stat;*/
	paddle* padle;
	ball* bal;

public:
	game();
	~game();

	clicktype getMouseClick(int& x, int& y) const;//Get coordinate where user clicks and returns click type (left/right)
	string getSrting() const;	 //Returns a string entered by the user


	window* CreateWind(int, int, int, int) const; //creates the game window


	void clearStatusBar() const;	//Clears the status bar


	void printMessage(string msg) const;	//Print a message on Status bar
	void playStatusBar() const;
	void go() const;

	window* getWind() const;		//returns a pointer to the graphics window

	grid* getGrid() const;
	MODE getMode() const;
	void setmode(MODE M);
	toolbar* getToolbar() const;
	paddle* getPaddle() const;
	ball* getBall() const;
	void updateTime(double i, double j) const;


	void setIsplay(bool p);
	void setIspause(bool p);

	void timer() const;
};

