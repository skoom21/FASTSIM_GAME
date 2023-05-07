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


using namespace std;
using namespace sf;

class MovementComponent
{
private:
	Sprite& sprite;
	float maxVelocity;
	float acceleration;
	float deceleration;
	Vector2f velocity;
	//Initializer functions

public:
	MovementComponent(Sprite& sprite, float maxVelocity);
	~MovementComponent();

	//Accessors
	const float& getmaxVelocity() const;
	const Vector2f& getvelocity() const;

	//Functions
	//const bool getState(const short unsigned state) const;
	void move(const float dir_x, const float dir_y, const float& dt);
	void update(const float& dt);
};