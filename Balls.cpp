#include "Balls.h"

void Balls::initVariables()
{

}

void Balls::initShape(const RenderWindow& window)
{
	//random color and radius
	this->shape.setRadius(static_cast<float>(rand() % 20 + 3));
	//switch for deciding type color
	Color color;
	switch(this->type)
	{
	case balltypes::DEFAULT:
		this->shape.setFillColor(Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
		this->shape.setOutlineColor(Color::Red);
		this->shape.setOutlineThickness(2.f);
		break;
	case balltypes::DAMAGING:
		this->shape.setFillColor(Color::Red);
		this->shape.setOutlineColor(Color::White);
		this->shape.setOutlineThickness(2.f);
		break;
	case balltypes::HEALING:
		this->shape.setFillColor(Color::Green);
		this->shape.setOutlineColor(Color::White);
		this->shape.setOutlineThickness(2.f);
		break;
	default:
		break;
	}

	this->shape.setPosition(
		Vector2f(
			static_cast <float>(rand() % window.getSize().x - this->getGlobadBounds().width),
			static_cast <float>(rand() % window.getSize().y - this->getGlobadBounds().height)
		)
	);

}

// Balls::Balls()
// {
// 	this->initVariables();
// 	this->initShape();
// }

Balls::Balls(RenderWindow& window, int type):type(type)
{
	this->initVariables();
	this->initShape(window);
}

Balls::~Balls()
{

}

const FloatRect Balls::getGlobadBounds() const
{
	return FloatRect();
}

const CircleShape Balls::getShape() const
{
	return this->shape;
}

const int& Balls::gettype() const
{
	return this->type;
}

void Balls::updateinput()
{

}

// void Balls::update(RenderTarget& target)
// {
// 	this->shape.move(0.f, 1.f);
// 	if (this->shape.getPosition().y > target.getSize().y)
// 	{
// 		this->shape.setPosition(Vector2f(rand() % 700 + 1, 0.f));
// 	}

// }


void Balls::render(RenderTarget& target)
{
	target.draw(this->shape);

}
