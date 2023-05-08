#pragma once
#include "State.h"
#include "Button.h"
class PauseMenu
{
private:
	Font& font;
	Text menutext;
	RectangleShape background;
	RectangleShape container;
	map<string, Button*> buttons;
public:
	PauseMenu(RenderWindow& window, Font& font);
	virtual ~PauseMenu();
	//Accessors
	map<string, Button*>& getbuttons();
	//Functions
	void addbutton(const string key, float x, float y, const string text);
	void update(Vector2f& mouseposwindow);
	void render(RenderTarget& target);
};