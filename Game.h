#pragma once

#include "Player.h"
#include "MainMenuState.h"
#include "Animation.h"

class game
{
private:
	//Variables
	//window
	RenderWindow* window;
	VideoMode videomode;
	vector <VideoMode> videomodes;
	ContextSettings window_settings;
	//View
	View* view;
	bool fullscreen;

	//Event
	Event ev;
	//states
	stack <State*> states;
	//map
	map <string, int> supportedkeys;
	Clock clock;
	float dt;
	//World


	//Private Functions
	void initstates();
	void initkeybinds();
	void initWorldBackground();
	void initfonts();
	void initText();
	void initenimies();
	void initvars();
	void initview();
	void initwindow();
public:
	game();
	~game();
	bool getwindowisopen();
	void endapplication();
	//void spawnballs();
	void run();
	//void renderenemy(RenderTarget& target);
	void render();
	///void renderWorld();
	//oid renderText(RenderTarget& target);
	void updatedt();
	//void updateenemy();
	// void updateCollision();
	//void updatemousepos();
	void updateEvents();
	void update();
	//void updateText();
};