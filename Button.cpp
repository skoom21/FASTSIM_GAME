#include "Button.h"
//constructor/destructor
//button constructor that takes in size position and color and font and text
Button::Button(float width, float height , float x, float y, Color idlecColor, Color hoverColor, Color activeColor, Font* font, string text)
{
	this->idleColor = idlecColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;
	this->pressed = false;
	this->hover = false;
	this->buttonState = BTN_IDLE;
	this->button.setSize(Vector2f(width, height));
	this->button.setPosition(Vector2f(x, y));
	this->button.setFillColor(idlecColor);
	this->button.setOutlineThickness(1);
	this->button.setOutlineColor(Color::White);

	this->text.setFont(*font);
	this->text.setString(text);
	this->text.setCharacterSize(20);
	this->text.setFillColor(Color::White);
	this->text.setPosition(
		this->button.getPosition().x + (this->button.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->button.getPosition().y + (this->button.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
	);

}

Button::~Button()
{
}

bool Button::isPressed() const
{
	if (this->buttonState == BTN_ACTIVE)
	{
		return true;
	}
	return false;
}

const string Button::getText() const
{
	return string();
}

void Button::render(RenderTarget& target)
{
	target.draw(this->button);
	target.draw(this->text);
}

void Button::update(Vector2f mousePos)
{
	this->buttonState = BTN_IDLE;
	//Hover
	if (this->button.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = BTN_HOVER;
		this->hover = true;
		//Pressed
		if (this->hover)
		{
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				this->buttonState = BTN_ACTIVE;
				this->pressed = true;
			}
		}
		else
		{
			this->pressed = false;
		}
	}
	else
	{
		this->buttonState = BTN_IDLE;
		this->hover = false;
	}
	//Update the button
	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->button.setFillColor(idleColor);
		break;
	case BTN_HOVER:
		this->button.setFillColor(hoverColor);
		break;
	case BTN_ACTIVE:
		this->button.setFillColor(activeColor);
		break;
	default:
		this->button.setFillColor(idleColor);
		break;
	}
}

bool Button::isClicked(Vector2f mousePos)
{
	if (this->button.getGlobalBounds().contains(mousePos))
	{
		return true;
	}
	return false;
}
