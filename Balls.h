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

enum balltypes { DEFAULT = 0, DAMAGING, HEALING, Nroftypes };

class Balls
{
private:

	//Variables
	CircleShape shape;
	Vector2f velocity;
	float movementSpeed;
	int type;
	//Private Functions
	void initVariables();
	void initShape(const RenderWindow& window);
public:
	//Constructors / Destructors
	Balls();
	Balls(RenderWindow& window,int type);
	virtual ~Balls();

	//Accessors
	const FloatRect getGlobadBounds() const;
	const CircleShape getShape() const;
	const int& gettype() const;

	//Functions
	void updateinput();
	void update(RenderTarget& target);
	void render(RenderTarget& target);
};
