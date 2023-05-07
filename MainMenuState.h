//Class for main menu of the game that inherits from state class
#pragma once
#include "GameState.h"
#include "Button.h"

using namespace std;
using namespace sf;

class MainMenuState :public State
{
private:
	//Variables
	Texture backgroundTexture;
	RectangleShape background;
	Font font;
	map<string, Button*> buttons;

	//Functions
	void initVariables();
	void initBackground();
	void initFonts();
	void initkeybinds();
	void initButtons();

public:
	//Constructors/Destructors
	MainMenuState(RenderWindow* window, map<string, int>* supportedKeys, stack<State*>* states);
	virtual ~MainMenuState();

	//Functions
	void updateinput(const float& dt);
	void updateButtons();
	void update(const float& dt, RenderTarget* target = nullptr	);
	void renderButtons(RenderTarget& target);
	void render(RenderTarget* target = nullptr);
};