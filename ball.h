#pragma once
#include "collidable.h"
#include "game.h"
#include "gameConfig.h"
#include "CMUgraphicsLib/auxil.h"
#include "paddle.h"
#include "Power.h"


class ball : public collidable
{
private:
	window* pWind;
	int Yinc = 5;
	int Xinc = 5;
	point prevUprLft;
	grid* bricksgrid;
	Power* POW;
protected:
	CollisionInfo CI;
public:
	ball(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~ball();
	void Balllaunch();
	void draw();
	void collisionAction();
	CollisionInfo checkCollision(collidable* obj);
	void setYinc(int y);
	void setXinc(int x);
	void setYinc(float y);
	void setXinc(float x);
	void set_power(Power* p);
	Power* get_power();
};

