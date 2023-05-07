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
#include "Animation.h"

using namespace std;
using namespace sf;

class GameTile
{
private:

	//Variables
	Animation *animation;
	Sprite sprite;
	Texture texture;
	RectangleShape shape;
	Vector2f velocity;
	Clock clock;
	bool isFree;
	bool isExit;

	float movementSpeed;
	int HP;
	int HPMax;

	//Private Functions
	void initVariables();
	void initShape();
	void initTexture();
	void initSprite();
public:
	GameTile();
	virtual ~GameTile();
	
};