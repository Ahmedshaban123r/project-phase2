#pragma once

#include "drawable.h"
#include "Bricks.h"


class game;

class grid:public drawable
{
	
	brick*** brickMatrix;		//2D array of brick pointers
	window* pWind;
	int rows, cols;
public:
	grid(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~grid();
	brick*** get_brickmatrix();
	int get_rows();	
	int get_cols();
	void draw() const;
	int addBrick(BrickType brkType, point clickedPoint);
	void destroy_brick(int R, int C);
	void deleteBrick(point clickedPoint);
};

