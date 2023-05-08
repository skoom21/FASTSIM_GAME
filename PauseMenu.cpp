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
	this->menutext.setCharacterSize(60);
	//set postion of the text to the mid top of the container
	this->menutext.setPosition(Vector2f(this->container.getPosition().x + this->container.getSize().x / 2.f  - 75.f
	,this->container.getPosition().y + 20.f));
}

PauseMenu::~PauseMenu()
{
	for (auto& i : this->buttons)
	{
		delete i.second;
	}
}

map<string, Button*>& PauseMenu::getbuttons()
{
	return this->buttons;
}

void PauseMenu::addbutton(const string key, float x, float y, const string text)
{
	this->buttons["Key"] = new Button(525, 185, 837, 198, Color(70, 70, 70, 200), Color(150, 150, 150, 255), Color(20, 20, 20, 200), &this->font, "Continue");
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
