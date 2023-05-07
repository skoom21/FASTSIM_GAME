#include "Entity.h"

const FloatRect Entity::getbounds() const
{
	return this->sprite.getGlobalBounds();
}

void Entity::setpos(const float x, const float y)
{
	this->sprite.setPosition(x,y);
}

void Entity::updateWindowBoundColision(RenderTarget* target)
{
	if (this->sprite.getPosition().x < 0.f)
	{
		this->sprite.setPosition(0.f, this->sprite.getPosition().y);
	}
	else if (this->sprite.getPosition().x + this->sprite.getGlobalBounds().width > target->getSize().x)
	{
		this->sprite.setPosition(target->getSize().x - this->sprite.getGlobalBounds().width, this->sprite.getPosition().y);
	}
	else if (this->sprite.getPosition().y < 0.f)
	{
		this->sprite.setPosition(this->sprite.getPosition().x, 0.f);
	}
	else if (this->sprite.getPosition().y + this->sprite.getGlobalBounds().height > target->getSize().y)
	{
		this->sprite.setPosition(this->sprite.getPosition().x, target->getSize().y - this->sprite.getGlobalBounds().height);
	}
}

void Entity::movement(const float& dt, float dir_x, float dir_y)
{
	this->movementcomponent->move(dir_x, dir_y, dt);
	this->sprite.setTextureRect(this->animation->uvRect);
}

void Entity::updateAnimation(const float& dt,int row)
{
	if(this->animation)
	{
		this->animation->update(dt,row);
	}
}

void Entity::update(const float& dt)
{
	if (this->movementcomponent)
	{
		this->movementcomponent->update(dt);
	}
}

void Entity::render(RenderTarget& target)
{
	target.draw(this->sprite);
}

void Entity::initvariables()
{
	this->animation = nullptr;
	this->texture = nullptr;
	this->points = 0;
}

Entity::Entity()
{
	this->initvariables();
}

Entity::~Entity()
{
	delete this->texture;
	delete this->animation;
	delete this->movementcomponent;
}

void Entity::setTexture(Texture& texture)
{
	this->animation = new Animation(&texture, Vector2u(4, 4), 0.2f);
	this->texture = &texture;
	this->sprite.setTexture(texture);
	this->sprite.scale(0.15f, 0.15f);
	this->sprite.setPosition(0.f, 0.f);
	this->sprite.setTextureRect(IntRect(0, 0, 480, 270));
}

void Entity::createMovementComponent(const float maxVelocity)
{
	this->movementcomponent = new MovementComponent(this->sprite, maxVelocity);
}
