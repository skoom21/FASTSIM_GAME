#include "MovementComponent.h"

MovementComponent::MovementComponent(Sprite& sprite, float maxVelocity) :
	sprite(sprite)
{
	this->maxVelocity = maxVelocity;
	this->acceleration = 20.f;
	this->deceleration = 10.f;

}

MovementComponent::~MovementComponent()
{
}

const Vector2f& MovementComponent::getvelocity() const
{
	return this->velocity;
}

//Functions
void MovementComponent::move(const float dir_x, const float dir_y, const float& dt)
{
	/* Accelerating a sprite until it reaches the max velocity */
	this->velocity.x += this->acceleration * dir_x * dt;
	this->velocity.y += this->acceleration * dir_y * dt;
}

void MovementComponent::update(const float& dt)
{
	//Decelerates the sprite and controls the maximum velocity
	if (this->velocity.x > 0.f) //Check for positive x
	{
		if(this->velocity.x > this->maxVelocity)
			this->velocity.x = this->maxVelocity;
		//Deceleration
		this->velocity.x -= deceleration * dt;
		/*if (this->velocity.x < 0.f)
			this->velocity.x = 0.f;*/
	}
	else if (this->velocity.x < 0.f) //Check for negative x
	{
		if (this->velocity.x < -this->maxVelocity)
			this->velocity.x = -this->maxVelocity;
		//Deceleration
		this->velocity.x += deceleration * dt;
		/*if (this->velocity.x > 0.f)
			this->velocity.x = 0.f;*/
	}
	if (this->velocity.y > 0.f) //Check for positive y
	{
		if (this->velocity.y > this->maxVelocity)
			this->velocity.y = this->maxVelocity;
		//Deceleration
		this->velocity.y -= deceleration * dt;
		/*if (this->velocity.y < 0.f)
			this->velocity.y = 0.f;*/
	}
	else if (this->velocity.y < 0.f) //Check for negative y
	{
		if (this->velocity.y < -this->maxVelocity)
			this->velocity.y = -this->maxVelocity;
		//Deceleration
		this->velocity.y += deceleration * dt;
		/*if (this->velocity.y > 0.f)
			this->velocity.y = 0.f;*/
	}

	//Final move
	sprite.move(this->velocity * dt);
}
