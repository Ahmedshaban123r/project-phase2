#pragma once
#include "collidable.h"
#include "game.h"
#include "grid.h"
#include "gameConfig.h"


class paddle : public collidable
{
private:
	window* pWind;
	Power* POW;
public:
	paddle(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~paddle();
	void movement();
	void draw();
	void collisionAction();
	point getPoint();
	void setPoint(point p);
	void set_power(Power* p);
	Power* get_power();
};

