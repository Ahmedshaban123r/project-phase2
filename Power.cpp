#include "Power.h"

Power::Power(point r_uprleft, int r_width, int r_height, game* r_pGame) :collidable(r_uprleft, r_width, r_height, r_pGame)

{
	imageName = "images\\power.jpg";
}

void Power::movepower()
{
	pwind = pGame->getWind();
	pwind->SetPen(BLACK);
	pwind->SetBrush(BLACK);
	pwind->DrawCircle(uprLft.x + 10, uprLft.y + 10, 10);

	if (uprLft.y + height > config.paddleAreaHeight)
	{
		pwind->SetPen(config.bkGrndColor);
		pwind->SetBrush(config.bkGrndColor);
		pwind->DrawCircle(uprLft.x + 10, uprLft.y + 10, 10);
		auto pPad=pGame->getPaddle();
		auto pBall = pGame->getBall();
		if (this->checkCollision(pPad).collided)
		{
			pPad->set_power(this);
			pBall->set_power(this);

		}

	}
	else
	{
		pwind->SetPen(config.bkGrndColor);
		pwind->SetBrush(config.bkGrndColor);
		pGame->getGrid()->draw();
		uprLft.y = uprLft.y + Yinc;
		pwind->SetPen(BLACK);
		pwind->SetBrush(BLACK);
		pwind->DrawCircle(uprLft.x + 10, uprLft.y + 10, 10);
		Pause(20);
		pwind->UpdateBuffer();
	}
}

void Power::collisionAction()
{

}

void Power::setType(POWERS TYPE)
{
	PTYPE = TYPE;
}

POWERS Power::gettype()
{
	return PTYPE;
}
CollisionInfo Power::checkCollision(collidable* obj)
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


