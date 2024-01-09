#pragma once
//This file contains all classes bricks classes 
#include "collidable.h"
#include "Power.h"
#include "gameConfig.h"
enum BrickType	//add more brick types
{
	BRK_NRM,	//Normal Brick
	BRK_HRD,	//Hard Brick
	BRK_ROK,     //rock brick
	BRK_BOM,
	BRK_POW
	//TODO: Add more types
};

//////////////////////////////////////////////////  class brick  ///////////////////////////////////////
//Base class for all bricks
class brick :public collidable
{
private:
	int strength;
	BrickType type;
	Power* POW;
	
public:
	brick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~brick();
	point getpoint();
	void set_strength(int s);
	int get_strength();
	int On_Collision();
	void collisionAction();
	BrickType get_type();
	void set_type(BrickType t);
	Power* get_power();
	void set_power(Power* p);
};


////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
class normalBrick :public brick
{

public:
	normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
};


////////////////////////////////////////////////////  class hardBrick  /////////////////////////////////
class hardBrick :public brick
{
public:
	hardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
};



class bombBrick :public brick
{

public:
	bombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);

	void collisionAction();
};

////////////////////////////////////////////////////  class rockBrick  ////////////////////////////////

class rockBrick :public brick
{

public:
	rockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);

	void collisionAction();
};


////////////////////////////////////////////////////  class POWERUPBrick  /////////////////////////////////


class power_up_down_Brick : public brick
{
	
public:
	power_up_down_Brick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();



};


