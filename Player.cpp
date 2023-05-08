#include "Player.h"


void Player::initAnimationComponent()
{
	this->animation = new Animation(this->texture, Vector2u(4, 4), 0.2f);
}


void Player::initTexture()
{
	if (!this->texture->loadFromFile("content/Textures/Character.png"))
	{
		cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}

}

void Player::initVariables()
{
	this->points = 0;
}

void Player::initComponents()
{
	this->createMovementComponent(50.f);
	this->initAnimationComponent();

}

Player::Player(float x, float y, Texture& texture_sheet)
{
	this->texture = &texture_sheet;
	this->initVariables();
	this->initComponents();
	this->setTexture(texture_sheet);
	this->setpos(x,y);
}

Player::~Player()
{

}
// void Player::upateWindowBoundCollision(RenderWindow* window)
// {
// 	if (this->sprite->getPosition().x < 0.f)
// 	{
// 		this->sprite->setPosition(0.f, this->sprite->getPosition().y);
// 	}
// 	else if (this->sprite->getPosition().x + this->sprite->getGlobalBounds().width > window->getSize().x)
// 	{
// 		this->sprite->setPosition(window->getSize().x - this->sprite->getGlobalBounds().width, this->sprite->getPosition().y);
// 	}
// 	else if (this->sprite->getPosition().y < 0.f)
// 	{
// 		this->sprite->setPosition(this->sprite->getPosition().x, 0.f);
// 	}
// 	else if (this->sprite->getPosition().y + this->sprite->getGlobalBounds().height > window->getSize().y)
// 	{
// 		this->sprite->setPosition(this->sprite->getPosition().x, window->getSize().y - this->sprite->getGlobalBounds().height);
// 	}
// }



