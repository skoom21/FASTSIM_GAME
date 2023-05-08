//SFML abstract class for handling various types of entities like tiles, sprites and other objects
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
#include "Animation.h"
#include "MovementComponent.h"

using namespace std;
using namespace sf;

class Entity
{
private:
	virtual void initvariables();
protected:
	//Variables
	Animation* animation;
	Texture* texture;
	Sprite sprite;
	MovementComponent* movementcomponent;
	Vector2f velocity;
	float dt;
	int points;
	//Functions
public:
	Entity();
	virtual ~Entity();
	//Component Functions
	virtual void setTexture(Texture& texture);
	virtual void createMovementComponent(const float maxVelocity);
	//Accessors
	//virtual vector
	virtual const Vector2f& getpos() const;
	virtual const FloatRect getbounds() const;
	//Modifiers
	virtual void setpos(const float x, const float y);
	//Functions
	virtual void updateWindowBoundColision(RenderTarget* target);
	virtual void movement(const float& dt, float dir_x, float dir_y);
	virtual void updateAnimation(const float& dt,int row);
	virtual void update(const float& dt);
	virtual void render(RenderTarget& target);
};