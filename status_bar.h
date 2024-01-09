//#pragma once
//#include "drawable.h"
//#include "game.h"
//#include "gameconfig.h"
//#include <chrono>
//
//
//class status_bar :
//	public drawable
//{
//	enum DATA {
//		LIVES,
//		SCORE,
//		TIME,
//		ICON_COUNT
//	};
//private:
//	statusbar_drawable** datalist;
//	game* pGame;
//	int score = 0;
//	int lives = 3;
//	window* wind;
//public:
//	status_bar(point r_uprleft, int r_width, int r_height, game* r_pGame);
//	void update_score();
//	void update_lives();
//	void update_time();
//	void draw();
//
//
//
//};
//
//
//class statusbar_drawable : public drawable
//{
//public:
//	statusbar_drawable(point r_uprleft, int r_width, int r_height, game* r_pGame);
//};
//class Score : public statusbar_drawable
//{
//public:
//	Score(point r_uprleft, int r_width, int r_height, game* r_pGame);
//};
//class Lives : public statusbar_drawable
//{
//public:
//	Lives(point r_uprleft, int r_width, int r_height, game* r_pGame);
//};
//class Time : public statusbar_drawable
//{
//public:
//	Time(point r_uprleft, int r_width, int r_height, game* r_pGame);
//};