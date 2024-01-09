#include "Bricks.h"
#include "grid.h"
#include<time.h>
#include<cstdlib>
////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
brick::brick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	collidable(r_uprleft, r_width, r_height, r_pGame) {}

brick::~brick() {}

point brick::getpoint() { return uprLft; }

void brick::set_strength(int s) { strength = s; }

int brick::get_strength() { return strength; }

int brick::On_Collision()
{
	strength--;
	return strength;
}

void brick::collisionAction()
{

}
Power* brick::get_power()
{
	return POW;
}

void brick::set_power(Power* p)
{
	POW = p;
}

BrickType brick::get_type()
{
	return type;
}

void brick::set_type(BrickType t)
{
	type = t;
}

////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
normalBrick::normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\NormalBrick.jpg";
	this->set_strength(1);
	set_type(BRK_NRM);
	set_power(nullptr);
}

void normalBrick::collisionAction()
{
	this->On_Collision();
}

hardBrick::hardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\hardBrick.jpg";

	this->set_strength(3);
	set_type(BRK_HRD);
	set_power(nullptr);
}

void hardBrick::collisionAction()
{
	this->On_Collision();
}



rockBrick::rockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\rockBrick.jpg";
	this->set_strength(1);
	set_type(BRK_ROK);
	set_power(nullptr);
}

void rockBrick::collisionAction()
{

}

power_up_down_Brick::power_up_down_Brick(point r_uprleft, int r_width, int r_height, game* r_pGame) :brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\NormalBrick.jpg";
	this->set_strength(1);
	set_type(BRK_POW);
	point NEWPOINT;
	NEWPOINT.x = uprLft.x + 20;
	NEWPOINT.y = uprLft.y + 5;
	Power* P = new Power(NEWPOINT, config.PowerWidth, config.Powerheight, r_pGame);
	set_power(P);
	srand(time(0));
	int random = rand() % 8;
	POWERS PTYPE = POWERS(random);
	get_power()->setType(PTYPE);
}

void power_up_down_Brick::collisionAction()
{
	this->On_Collision();
	if (this->get_strength() == 0)
	{
		get_power()->movepower();
	}
}



bombBrick::bombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :brick(r_uprleft, r_width, r_height, r_pGame)

{
	imageName = "images\\bricks\\BombBrick.jpeg";
	this->set_strength(1);
	set_type(BRK_BOM);
	set_power(nullptr);
}

void bombBrick::collisionAction()
{
	/*CollisionInfo CI = checkCollision(this, obj);
	if (CI.collided)
	{
		this->On_Collision();
	}
	if (this->get_strength() == 0)
	{

		grid* pGrid = pGame->getGrid();
		brick*** BM = pGrid->get_brickmatrix();
		for (int i = 0; i < pGrid->get_rows(); i++)
		{
			for (int j = 0; j < pGrid->get_cols(); j++)
			{
				if (BM[i][j]->getpoint().x == newBrickUpleft.x && BM[i][j]->getpoint().y == newBrickUpleft.y);
				pGrid->destroy_brick(BM[i][j]);
			}
		}
	}*/
}
//point uperleft;
// uperleft.x=this->uprlft.x+this->width
// uperleft.y=this->uprlft.y
//brick*b(uperleft)
//delete b


