//sfml class for dealing with buttons
#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/window.hpp>

using namespace std;
using namespace sf;

enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

class Button
{
private:
	bool pressed;
	bool hover;

	short unsigned buttonState; //0-idle, 1-hover, 2-active
	Color idleColor;
	Color hoverColor;
	Color activeColor;

	RectangleShape button;
	Text text;

public:
//constructor/destructor
	Button(float width, float height , float x, float y, Color idlecColor, Color hoverColor, Color activeColor, Font* font, string text);
	~Button();
//accessors
	bool isPressed() const;
	const string getText() const;
//functions
	void render(RenderTarget &target);
	void update(Vector2f mousePos);
	bool isClicked(Vector2f mousePos);
};