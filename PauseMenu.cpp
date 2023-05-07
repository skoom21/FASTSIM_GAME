#include "PauseMenu.h"

PauseMenu::PauseMenu(RenderWindow& window, Font& font): font(font)
{
	//innit background
	this->background.setSize(Vector2f(window.getSize().x, window.getSize().y));
	this->background.setFillColor(Color(20, 20, 20, 50));
	//innit Container
	this->container.setSize(Vector2f(window.getSize().x / 4.f, window.getSize().y - 100.f));
	this->container.setFillColor(Color(20, 20, 20, 200));
	this->container.setPosition(Vector2f(window.getSize().x / 2.f - this->container.getSize().x / 2.f, 30.f));
	//innit text
	this->menutext.setFont(font);
	this->menutext.setString("PAUSED");
	this->menutext.setCharacterSize(50);
	//set postion of the text to the mid top of the container
	this->menutext.setPosition(Vector2f(this->container.getPosition().x + this->menutext.getGlobalBounds().width, this->container.getPosition().y + 40.f));
}

PauseMenu::~PauseMenu()
{
	for (auto& i : this->buttons)
	{
		delete i.second;
	}
}

void PauseMenu::update(Vector2f& mouseposwindow)
{
	for (auto& i : this->buttons)
	{
		i.second->update(mouseposwindow);
	}
}

void PauseMenu::render(RenderTarget& target)
{
	target.draw(this->background);
	target.draw(this->container);
	target.draw(this->menutext);
	for (auto& i : this->buttons)
	{
		i.second->render(target);
	}
}
