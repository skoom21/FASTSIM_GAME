#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/window.hpp>
#include "Player.h"

using namespace std;
using namespace sf;

class State
{
protected:
	RenderWindow* window;
	stack<State*>* states;
	map<string, int>* supportedkeys;
	map<string, int> keybinds;
	map <string, Texture> textures;
	//Mouse position
	Vector2i mouseposscreen;
	Vector2i mouseposwindow;
	Vector2f mouseposview;
	bool quit;
	bool paused;
	//Functions
	virtual void initkeybinds() = 0;

public:
	State(RenderWindow* window, map <string, int>* supportedkeys,stack<State*>* states);
	virtual ~State();
	const bool& getquit() const;
	//Functions
	void updatemousepos();
	void pausestate();
	void unpausedstate();
	virtual void endState();
	virtual void updateinput(const float& dt) = 0;
	virtual void update(const float& dt,RenderTarget* target=nullptr) = 0;
	virtual void render(RenderTarget* target = nullptr) = 0;
};