#include "status_bar.h"

status_bar::status_bar(point r_uprleft, int r_width, int r_height, game* r_pGame) : drawable(r_uprleft, r_width, r_height, r_pGame)
{
	lives = 3;
	score = 0;

}

void status_bar::update_score()
{

	score += 1;
	wind->SetBrush(RED);
	wind->SetPen(RED);
	wind->DrawRectangle(1100, 0, 1200, 50);
	wind->SetBrush(WHITE);
	wind->SetPen(WHITE);
	wind->DrawInteger(config.windWidth - 100, 0, score);
}

void status_bar::update_lives()
{
	lives -= 1;
	wind->SetBrush(RED);
	wind->SetPen(RED);
	wind->DrawRectangle(1000, 0, 1100, 50);
	wind->SetBrush(WHITE);
	wind->SetPen(WHITE);
	wind->DrawInteger(config.windWidth - 200, 0, lives);

}

void status_bar::update_time()
{
	wind->SetBrush(RED);
	wind->SetPen(RED);
	wind->DrawRectangle(800, 0, 1000, 50);
	chrono::steady_clock::time_point startTime;
	// Calculate the elapsed time since the game started
	auto currentTime = std::chrono::steady_clock::now();
	auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);
	// Calculate minutes and seconds
	int minutes = elapsedSeconds.count() / 60;
	int seconds = elapsedSeconds.count() % 60;
	//this->r_pGame->
	wind->DrawInteger(config.windWidth - 300, 0, seconds);
	if (minutes!=0)
		wind->DrawInteger(config.windWidth - 400, 0, minutes);


}

void status_bar::draw()
{
	window* wind = pGame->getWind;
	Wind->SetPen(RED, 3);
	pWind->DrawLine(0, height, wind->GetWidth(), height);
	//draw status bar
	wind->SetBrush(RED);
	wind->SetPen(RED);
	wind->DrawRectangle(800, 550, 1200, 600);
	//set color
	wind->SetBrush(WHITE);
	wind->SetPen(WHITE);
	//draw score
	wind->DrawInteger(config.windWidth - 100, 0, score);
	//draw live
	wind->DrawInteger(config.windWidth - 200, 0, lives);
	//draw time
	wind->DrawInteger(config.windWidth - 400, 0, 00);
}
