#pragma once
#include "collidable.h"
#include <iostream>
#include "gameConfig.h"
#include "game.h"
#include"paddle.h"
#include "ball.h"
using namespace std;



enum POWERS
{
	FIRE_BALL,
	WIND_GLIDE,
	WIDE_PADDLE,
	NARROW_PADDLE,
	MAGNET,
	MULTI_BALLS,
	REV_DRIECTION,
	QUICKSAND
};
class Power : public collidable
{
private:
	window* pwind;
	int Yinc = 3;
	POWERS PTYPE;
	CollisionInfo CI;
public:
	Power(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void movepower();
	void collisionAction();
	void setType(POWERS TYPE);
	POWERS gettype();
	CollisionInfo checkCollision(collidable* obj);
};