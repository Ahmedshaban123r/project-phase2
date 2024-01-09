#pragma once
#include <chrono>
//This file contains all classes related to toolbar (toolbar icon classes & toolbar class itself)
#include "drawable.h"


////////////////////////////////////////////////////  class toolbarIcon   ////////////////////////////////////////////////////
//Base class for all toolbar icons 
class toolbarIcon :public drawable
{
public:
	toolbarIcon(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick() = 0;   //The action that should be taken when this icon is clicked
};

////////////////////////////////////////////////////  class iconAddNormalBrick   //////////////////////////////////////////////
class iconAddNormalBrick :public toolbarIcon
{
public:
	iconAddNormalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();
};

////////////////////////////////////////////////////  class iconAddHardBrick   //////////////////////////////////////////////
class iconAddHardBrick :public toolbarIcon
{

public:
	iconAddHardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();
};

////////////////////////////////////////////////////  class iconAddRockBrick   //////////////////////////////////////////////
class iconAddRockBrick :public toolbarIcon
{
public:
	iconAddRockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();
};
class iconAddBombBrick :public toolbarIcon
{
public:
	iconAddBombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();
};
////////////////////////////////////////////////////  class iconExit   //////////////////////////////////////////////
class iconExit :public toolbarIcon
{
public:
	iconExit(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();
};



class iconload :public toolbarIcon
{
private:

public:
	iconload(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();
};
class iconsave :public toolbarIcon
{
private:

public:
	iconsave(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();
};
class iconstop :public toolbarIcon
{
public:
	iconstop(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();
};
class icondelete:public toolbarIcon
{
public:
	icondelete(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();

};
class iconpause :public toolbarIcon
{
public:
	iconpause(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();
};
class iconplay :public toolbarIcon
{
public:
	iconplay(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();
};






////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
class toolbar :public drawable
{
	//Icon i1=round(0,6)
	enum ICONS //The icons of the toolbar (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_ADD_NORM,		//add normal brick
		ICON_ADD_HARD,
		ICON_ADD_ROCK,
		ICON_ADD_BOMB,
		ICON_ADD_POWER,
		ICON_DEL_BRICK,
		ICON_LOAD,
		ICON_SAVE,
		ICON_EXIT,
		//TODO: Add more icons names here
		ICON_PLAY,
		ICON_STOP,
		ICON_PAUSE,
			//Exit icon

		ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};

private:
	toolbarIcon** iconsList; //an array of toolbarIcon pointers
	string iconsImages[ICON_COUNT];
	game* pGame;
	int Lives=3;
	int score=0;
	window* pwind;

public:
	toolbar(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~toolbar();
	void draw() const;
	bool handleClick(int x, int y);
	int getLives();
	int getScore();
	int updateLives();
	//handles clicks on toolbar icons, returns true if exit is clicked
};