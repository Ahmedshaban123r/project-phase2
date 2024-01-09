#include "paddle.h"

paddle::paddle(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	collidable(r_uprleft, r_width, r_height, r_pGame)
{

}

paddle::~paddle()
{
	pWind->SetPen(config.bkGrndColor);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(0, config.paddleAreaHeight, config.windWidth, config.paddleAreaHeight + 15);
}

void paddle::movement()
{
	switch (POW->gettype())
	{
	case WIND_GLIDE:
		pWind = pGame->getWind();
		//pWind->FlushKeyQueue();
		keytype k;
		char x;
		//do {
		k = pWind->GetKeyPress(x);
		if (k == ARROW) {
			switch (x) {
			case 4:
				if (this->uprLft.x > 0) {
					pWind->SetPen(config.bkGrndColor);
					pWind->SetBrush(config.bkGrndColor);
					pWind->DrawRectangle(0, config.paddleAreaHeight, config.windWidth, config.paddleAreaHeight + 15);
					this->uprLft.x -= 70;
					this->draw();

				}
				break;
			case 6:
				if (this->uprLft.x + config.paddleWidth < config.windWidth) {
					pWind->SetPen(config.bkGrndColor);
					pWind->SetBrush(config.bkGrndColor);
					pWind->DrawRectangle(0, config.paddleAreaHeight, config.windWidth, config.paddleAreaHeight + 15);
					this->uprLft.x += 70;
					this->draw();

				}
				break;
			}
		}
		pWind->UpdateBuffer();
		//} while (k != ESCAPE);
		break;
	case REV_DRIECTION:
		pWind = pGame->getWind();
		//pWind->FlushKeyQueue();
		keytype k;
		char x;
		//do {
		k = pWind->GetKeyPress(x);
		if (k == ARROW) {
			switch (x) {
			case 4:
				if (this->uprLft.x > 0) {
					pWind->SetPen(config.bkGrndColor);
					pWind->SetBrush(config.bkGrndColor);
					pWind->DrawRectangle(0, config.paddleAreaHeight, config.windWidth, config.paddleAreaHeight + 15);
					this->uprLft.x += 50;
					this->draw();

				}
				break;
			case 6:
				if (this->uprLft.x + config.paddleWidth < config.windWidth) {
					pWind->SetPen(config.bkGrndColor);
					pWind->SetBrush(config.bkGrndColor);
					pWind->DrawRectangle(0, config.paddleAreaHeight, config.windWidth, config.paddleAreaHeight + 15);
					this->uprLft.x -= 50;
					this->draw();

				}
				break;
			}
		}
		pWind->UpdateBuffer();
		//} while (k != ESCAPE);
	case QUICKSAND:
		pWind = pGame->getWind();
		//pWind->FlushKeyQueue();
		keytype k;
		char x;
		//do {
		k = pWind->GetKeyPress(x);
		if (k == ARROW) {
			switch (x) {
			case 4:
				if (this->uprLft.x > 0) {
					pWind->SetPen(config.bkGrndColor);
					pWind->SetBrush(config.bkGrndColor);
					pWind->DrawRectangle(0, config.paddleAreaHeight, config.windWidth, config.paddleAreaHeight + 15);
					this->uprLft.x -= 25;
					this->draw();

				}
				break;
			case 6:
				if (this->uprLft.x + config.paddleWidth < config.windWidth) {
					pWind->SetPen(config.bkGrndColor);
					pWind->SetBrush(config.bkGrndColor);
					pWind->DrawRectangle(0, config.paddleAreaHeight, config.windWidth, config.paddleAreaHeight + 15);
					this->uprLft.x += 25;
					this->draw();

				}
				break;
			}
		}
		pWind->UpdateBuffer();
		//} while (k != ESCAPE);

	default:
		pWind = pGame->getWind();
		//pWind->FlushKeyQueue();
		keytype k;
		char x;
		//do {
		k = pWind->GetKeyPress(x);
		if (k == ARROW) {
			switch (x) {
			case 4:
				if (this->uprLft.x > 0) {
					pWind->SetPen(config.bkGrndColor);
					pWind->SetBrush(config.bkGrndColor);
					pWind->DrawRectangle(0, config.paddleAreaHeight, config.windWidth, config.paddleAreaHeight + 15);
					this->uprLft.x -= 50;
					this->draw();

				}
				break;
			case 6:
				if (this->uprLft.x + config.paddleWidth < config.windWidth) {
					pWind->SetPen(config.bkGrndColor);
					pWind->SetBrush(config.bkGrndColor);
					pWind->DrawRectangle(0, config.paddleAreaHeight, config.windWidth, config.paddleAreaHeight + 15);
					this->uprLft.x += 50;
					this->draw();

				}
				break;
			}
		}
		pWind->UpdateBuffer();
		//} while (k != ESCAPE);
		break;

	}
}

void paddle::draw()
{
	switch (POW->gettype())
	{
	case WIDE_PADDLE:
		pWind = pGame->getWind();
		pWind->SetBrush(FORESTGREEN);
		pWind->SetPen(FORESTGREEN);
		pWind->DrawRectangle(this->uprLft.x, config.paddleAreaHeight, this->uprLft.x + (config.paddleWidth * 2), config.paddleAreaHeight + 15);
		break;
	case NARROW_PADDLE:
		pWind = pGame->getWind();
		pWind->SetBrush(FORESTGREEN);
		pWind->SetPen(FORESTGREEN);
		pWind->DrawRectangle(this->uprLft.x, config.paddleAreaHeight, this->uprLft.x + (config.paddleWidth / 2), config.paddleAreaHeight + 15);
		break;
	default:
		pWind = pGame->getWind();
		pWind->SetBrush(FORESTGREEN);
		pWind->SetPen(FORESTGREEN);
		pWind->DrawRectangle(this->uprLft.x, config.paddleAreaHeight, this->uprLft.x + config.paddleWidth, config.paddleAreaHeight + 15);
	}
}

void paddle::collisionAction()
{
}

point paddle::getPoint()
{
	return this->uprLft;
}

void paddle::setPoint(point p)
{
	uprLft.x = p.x;
	uprLft.y = p.y;
}

void paddle::set_power(Power *p)
{
	POW = p;
}

Power* paddle::get_power()
{
	return POW;
}



