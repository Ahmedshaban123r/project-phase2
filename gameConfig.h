#pragma once
#include "CMUgraphicsLib/CMUgraphics.h"

__declspec(selectany) //This line to prevent "redefinition error"
struct 		//contains all game configurations (MAY be loaded from a configuration file later)
{
	int	windWidth = 1200, windHeight = 600,	//Window width and height
		wx = 5, wy = 5,			//Window starting coordinates

		//The window is divded into 4 areas: toolbar, bricks grid area, paddle area, statusbar
		toolBarHeight = 40,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		statusBarHeight = 50;	//Status Bar Height

	int remainingHeight = windHeight - toolBarHeight - statusBarHeight;

	int gridHeight = int(remainingHeight * (2 / 3.0)); 		//The grid is where bricks can be drawn
/*	int paddleAreaHeight = remainingHeight - gridHeight;*/	//The area dedicated for paddle
	int paddleAreaHeight = 500;
	color	penColor = BLUE,			//color used to draw lines/write messages
		bkGrndColor = LAVENDER,		//Background color
		statusBarColor = LIGHTSEAGREEN;	//background color of the status
	int penWidth = 3;			//width of the pen that draws shapes


	int statusbaricon = (7 * 70)+20;
	int brickWidth = 60;
	int brickHeight = 30;
	color gridLinesColor = NAVYBLUE;

	int balldiam = 25;

	int paddleWidth = 150;
	int paddleHeight = 15;

	int ballrectX1 = (windWidth / 2) - (balldiam / 2);
	int ballrectX2 = ballrectX1 + balldiam;
	int ballrectY1 = paddleAreaHeight - balldiam;
	int ballrectY2 = ballrectY1 + balldiam;

	int	iconWidth = 70;		
	double i = 1; double j = 0;
	double timer = 0;
	//Width of each icon in toolbar 	
	int Powerheight = 20;
	int PowerWidth = 20;
}config;