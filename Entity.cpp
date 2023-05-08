#include "Entity.h"

const Vector2f &Entity::getpos() const
{
	return this->sprite.getPosition();
}

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
	//Left
	if (this->getbounds().left < 0.f)
	{
		this->setpos(0.f, this->getbounds().top);
	}
	//Right
	else if (this->getbounds().left + this->getbounds().width > target->getSize().x)
	{
		this->setpos(target->getSize().x - this->getbounds().width, this->getbounds().top);
	}
	//Top
	if (this->getbounds().top < 0.f)
	{
		this->setpos(this->getbounds().left, 0.f);
	}
	//Bottom
	else if (this->getbounds().top + this->getbounds().height > target->getSize().y)
	{
		this->setpos(this->getbounds().left, target->getSize().y - this->getbounds().height);
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
