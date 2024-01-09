#define _USE_MATH_DEFINES
#include "ball.h"
#include <cmath>



ball::ball(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	collidable(r_uprleft, r_width, r_height, r_pGame)
{

}

ball::~ball()
{
	pGame->getGrid()->draw();
	pWind->SetBrush(config.bkGrndColor);
	pWind->SetPen(config.bkGrndColor);
	pWind->DrawCircle(config.ballrectX1 + config.balldiam / 2, config.ballrectY1 + config.balldiam / 2, config.balldiam / 2);

}
void ball::set_power(Power* p)
{
	POW = p;
}

Power* ball::get_power()
{
	return POW;
}

void ball::Balllaunch()
{
	bricksgrid = pGame->getGrid();
	pWind = pGame->getWind();
	pWind->SetBrush(config.bkGrndColor);
	pWind->SetPen(config.bkGrndColor);
	paddle* p = pGame->getPaddle();

	prevUprLft.x = config.ballrectX1 - Xinc;
	prevUprLft.y = config.ballrectY1 + Yinc;


	pWind->DrawCircle((prevUprLft.x + config.balldiam / 2), (prevUprLft.y + config.balldiam / 2), config.balldiam / 2);

	config.ballrectX1 += Xinc;
	config.ballrectX2 += Xinc;
	config.ballrectY1 -= Yinc;
	config.ballrectY2 -= Yinc;


	if (config.ballrectY1 <= config.gridHeight + config.toolBarHeight)
	{
		int rows = bricksgrid->get_rows();
		int columns = bricksgrid->get_cols();
		brick*** BricksMatrix = bricksgrid->get_brickmatrix();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				switch (POW->gettype())
				{
				case FIRE_BALL:
					if (checkCollision(BricksMatrix[i][j]).collided)
					{
						if (BricksMatrix[i][j]->get_type() == BRK_POW)
						{
							BricksMatrix[i][j]->get_power()->movepower();
							bricksgrid->destroy_brick(i, j);
						}
						else
							bricksgrid->destroy_brick(i, j);
						if (config.ballrectX1 == checkCollision(BricksMatrix[i][j]).collisionPointX || config.ballrectX2 == checkCollision(BricksMatrix[i][j]).collisionPointX)
						{
							setXinc(-Xinc);

						}
						if (config.ballrectY1 == checkCollision(BricksMatrix[i][j]).collisionPointY || config.ballrectY2 == checkCollision(BricksMatrix[i][j]).collisionPointY)
						{
							setYinc(-Yinc);
						}
					}
					else
					{
						if (config.ballrectX1 == checkCollision(BricksMatrix[i][j]).collisionPointX || config.ballrectX2 == checkCollision(BricksMatrix[i][j]).collisionPointX)
						{
							setXinc(-Xinc);

						}
						if (config.ballrectY1 == checkCollision(BricksMatrix[i][j]).collisionPointY || config.ballrectY2 == checkCollision(BricksMatrix[i][j]).collisionPointY)
						{
							setYinc(-Yinc);
						}
					}
					
				case MULTI_BALLS:
					ball* b1 = new ball(uprLft, config.ballrectX1 + config.balldiam, config.ballrectY1 + config.balldiam, this->pGame);
					b1->setXinc(Xinc);
					b1->setYinc(Yinc - 2);
					b1->draw();
					b1->set_power(nullptr);
					b1->Balllaunch();
					ball* b2 = new ball(uprLft, config.ballrectX1 + config.balldiam, config.ballrectY1 + config.balldiam, this->pGame);
					b2->setXinc(Xinc - 2);
					b2->setYinc(Yinc);
					b2->draw();
					b2->set_power(nullptr);
					b2->Balllaunch();
					this->set_power(nullptr);
				default:
					if (checkCollision(BricksMatrix[i][j]).collided)
					{
						if (BricksMatrix[i][j]->get_strength() == 0)
						{
							if (BricksMatrix[i][j]->get_type() == BRK_POW)
						{	BricksMatrix[i][j]->get_power()->movepower();
							bricksgrid->destroy_brick(i, j);
						}
							else
							{
								if(BricksMatrix[i][j]->get_strength() == 0)
									bricksgrid->destroy_brick(i, j);
							}
							if (config.ballrectX1 == checkCollision(BricksMatrix[i][j]).collisionPointX || config.ballrectX2 == checkCollision(BricksMatrix[i][j]).collisionPointX)
							{
								setXinc(-Xinc);

							}
							if (config.ballrectY1 == checkCollision(BricksMatrix[i][j]).collisionPointY || config.ballrectY2 == checkCollision(BricksMatrix[i][j]).collisionPointY)
							{
								setYinc(-Yinc);
							}
						}
						else
						{
							if (config.ballrectX1 == checkCollision(BricksMatrix[i][j]).collisionPointX || config.ballrectX2 == checkCollision(BricksMatrix[i][j]).collisionPointX)
							{
								setXinc(-Xinc);

							}
							if (config.ballrectY1 == checkCollision(BricksMatrix[i][j]).collisionPointY || config.ballrectY2 == checkCollision(BricksMatrix[i][j]).collisionPointY)
							{
								setYinc(-Yinc);
							}
						}
					}
				}
			}
		}
	}

	if (config.ballrectY2 == config.paddleAreaHeight && config.ballrectX1 >= p->getPoint().x && config.ballrectX2 <= p->getPoint().x + config.paddleWidth) {
		//setYinc(-Yinc);
		if (config.ballrectX2 <= (p->getPoint().x + config.paddleWidth)/3) {
			setYinc(-Yinc);
			setXinc(-Yinc);
		}
		else if (config.ballrectX2 <= (p->getPoint().x + config.paddleWidth)*2/3) {
			setYinc(-Yinc);
		}
		if (config.ballrectX2 <= (p->getPoint().x + config.paddleWidth)) {
			setYinc(-Yinc);
			setXinc(Yinc);
		}
	}
	if (config.ballrectY1 >= p->getPoint().y)
	{
		pGame->getToolbar()->updateLives();
		//pGame->setmode(MODE_DSIGN);
		pWind->SetBrush(config.bkGrndColor);
		pWind->SetPen(config.bkGrndColor);
		pWind->DrawRectangle(0, config.paddleAreaHeight, config.windWidth, config.windHeight - config.statusBarHeight);
		config.ballrectX1 = (config.windWidth / 2) - (config.balldiam / 2);
		config.ballrectX2 = config.ballrectX1 + config.balldiam;
		config.ballrectY1 = config.paddleAreaHeight - config.balldiam;
		config.ballrectY2 = config.ballrectY1 + config.balldiam;
		//pGame->setmode(MODE_PLAY);
		point PP = { (config.windWidth / 2) - (config.paddleWidth / 2) , config.paddleAreaHeight };
		p->setPoint(PP);
		this->draw();
		p->draw();
		pWind->FlushKeyQueue();
		keytype Q;
		char Cha;
		Q = pWind->WaitKeyPress(Cha);
		if (Q == ASCII && Cha == ' ') {
			setXinc(5);
			setYinc(5);
			pWind->SetBrush(config.gridLinesColor);
			pWind->SetPen(config.gridLinesColor);
			pGame->getGrid()->draw();
		}

	}
	if (POW->gettype() == MAGNET) {
		pGame->getGrid()->draw();
		config.ballrectX1 = p->getPoint().x - (config.balldiam / 2);
		config.ballrectX2 = config.ballrectX1 + config.balldiam;
		config.ballrectY1 = p->getPoint().y - config.balldiam;
		config.ballrectY2 = config.ballrectY1 + config.balldiam;
		//pGame->setmode(MODE_PLAY);
		this->draw();
		pWind->FlushKeyQueue();
		keytype Q;
		char Cha;
		Q = pWind->WaitKeyPress(Cha);
		if (Q == ASCII && Cha == ' ') {
			setXinc(5);
			setYinc(5);
			pWind->SetBrush(config.gridLinesColor);
			pWind->SetPen(config.gridLinesColor);
		}

	}


	if (config.ballrectX2 >= config.windWidth - 5) {
		setXinc(-Xinc);
	}
	if (config.ballrectX1 <= 0) {
		setXinc(-Xinc);
	}
	if (config.ballrectY2 >= config.windHeight - config.statusBarHeight - 5) {
		setYinc(-Yinc);
	}
	if (config.ballrectY1 <= config.toolBarHeight + 10) {
		setYinc(-Yinc);
	}

	//if (config.ballrectY1 <= config.toolBarHeight + 10) {
	//	config.ballrectY1 = -config.ballrectY1;
	//}


	//config.ballrectY1 -= 5;
	this->draw();

	pGame->getGrid()->draw();
	p->draw();
	Pause(20);
	pWind->UpdateBuffer();

}


void ball::draw()
{
	pWind = pGame->getWind();
	pWind->SetPen(config.bkGrndColor);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(config.ballrectX1, config.ballrectY1, config.ballrectX2, config.ballrectY2);
	pWind->SetPen(NAVYBLUE);
	pWind->SetBrush(NAVYBLUE);
	pWind->DrawCircle(config.ballrectX1 + config.balldiam / 2, config.ballrectY1 + config.balldiam / 2, config.balldiam / 2);
}

void ball::collisionAction()
{
	//if (config.ballrectX1 == checkCollision().collisionPointX)

}

CollisionInfo ball::checkCollision(collidable* obj)
{

	CI.collided = false;
	if (obj != nullptr) {
		int objLeft = obj->getPoint().x;
		int objRight = objLeft + obj->getWidth();
		int objTop = obj->getPoint().y;
		int objBot = objTop + obj->getHeight();

		int left = config.ballrectX1;
		int right = config.ballrectX2;
		int top = config.ballrectY1;
		int bot = config.ballrectY2;

		//Check if bounding boxes overlap for left or right sides
		//calculating the collision point(x, y)


		if (objLeft == right) {
			if (objTop <= top && objTop >= bot) {
				CI.collided = true;
				CI.collisionPointX = objLeft;
				CI.collisionPointY = objTop + ((bot - objTop) / 2);
			}
			else if (objBot >= top && objBot <= bot) {
				CI.collided = true;
				CI.collisionPointX = objLeft;
				CI.collisionPointY = top + ((objBot - top) / 2);
			}
			else if (top <= objTop && bot >= objBot) {
				CI.collided = true;
				CI.collisionPointX = objLeft;
				CI.collisionPointY = top + ((bot - top) / 2);
			}
		}




		if (objRight == left) {
			if (objTop <= top && objTop >= bot) {
				CI.collided = true;
				CI.collisionPointX = objRight;
				CI.collisionPointY = objTop + ((bot - objTop) / 2);
			}
			else if (objBot >= top && objBot <= bot) {
				CI.collided = true;
				CI.collisionPointX = objRight;
				CI.collisionPointY = top + ((objBot - top) / 2);
			}
			else if (top <= objTop && bot >= objBot) {
				CI.collided = true;
				CI.collisionPointX = objRight;
				CI.collisionPointY = top + ((bot - top) / 2);
			}
		}



		//Check if bounding boxes overlap for top or bottom sides
		//calculating the collision point(x, y)


		if (objBot == top) {
			if (objRight >= left && objRight <= right) {
				CI.collided = true;
				CI.collisionPointX = objLeft + ((objRight - left) / 2);
				CI.collisionPointY = objBot;
			}
			else if (left <= objLeft && right >= objLeft) {
				CI.collided = true;
				CI.collisionPointX = left + ((objLeft - left) / 2);
				CI.collisionPointY = objBot;
			}
			else if (left >= objLeft && right <= objRight) {
				CI.collided = true;
				CI.collisionPointX = left + ((right - left) / 2);
				CI.collisionPointY = objBot;
			}
		}



		if (objTop == bot) {
			if (objRight >= left && objRight <= right) {
				CI.collided = true;
				CI.collisionPointX = objLeft + ((objRight - left) / 2);
				CI.collisionPointY = objTop;
			}
			else if (left <= objLeft && right >= objLeft) {
				CI.collided = true;
				CI.collisionPointX = left + ((objLeft - left) / 2);
				CI.collisionPointY = objTop;
			}
			else if (left >= objLeft && right <= objRight) {
				CI.collided = true;
				CI.collisionPointX = left + ((right - left) / 2);
				CI.collisionPointY = objTop;
			}
		}
	}

	return CI;
}

void ball::setYinc(int y)
{
	Yinc = y;
}

void ball::setXinc(int x)
{
	Xinc = x;
}

void ball::setYinc(float y)
{
	Yinc = y;
}

void ball::setXinc(float x)
{
	Xinc = x;
}
