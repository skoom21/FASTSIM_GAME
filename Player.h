#pragma once

#include "Entity.h"
using namespace std;
using namespace sf;

class Player:public Entity
{

private:
	//Variables
	//Functions
	void initSprite();
	void initTexture();
	void initVariables();
	void initComponents();
	void initAnimationComponent();
public:
	Player(float x, float y, Texture& texture_sheet);
	virtual ~Player();

	//Accessors
	//Modifiers

	//Functions
	//void movement(const float& dt, float dir_x, float dir_y);
	//void update(RenderTarget* target);
	//bool updateInput(const float& dt, map <string, int> keybinds);
	//void updateAnimation(const float& dt);
	//void upateWindowBoundCollision(RenderWindow* window);
	//void updatesprite();
	//void render(RenderTarget* target);

};







































// class Player : public Entity
// {
// private:
// 	//Variables
// 	Animation* animation;
// 	Texture* texture;
// 	Sprite sprite;
// 	Vector2f velocity;
// 	float dt;
// 	float movementSpeed;
// 	int points;
// 	//Functions
// 	void initSprite();
// 	void initTexture();
// 	void initVariables();
// 	void initComponents();

// public:
// 	Player(float x, float y, Texture *texture_sheet);
// 	virtual ~Player();

// 	//Accessors
// 	const Sprite& getShape() const;
// 	//Modifiers

// 	//Functions
// 	void movement(const float& dt, float dir_x, float dir_y);
// 	void update(const float& dt);
// 	void upateWindowBoundsCollision(const float& dt);
// 	void updatesprite();
// 	void updateInput();
// 	void render(RenderTarget& target);
// };