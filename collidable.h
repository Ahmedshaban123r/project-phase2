#pragma once
#include "drawable.h"
struct CollisionInfo
{
	bool collided;
	int collisionPointX;
	int collisionPointY;
};
///////////////////////////////////////   collidable classes   /////////////////////////////////
//Base class for all collidable (objects that may collide with other objects)
class collidable :public drawable
{
	CollisionInfo CI1;
public:
    collidable(point r_uprleft, int r_width, int r_height, game* r_pGame);
   
    virtual void collisionAction() = 0;    //action that should be performed upon collision
    CollisionInfo checkCollision(collidable*obj1,collidable* obj2);
	point getPoint();
	int getWidth();
	int getHeight();
};

