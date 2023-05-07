#include "State.h"

State::State(RenderWindow* window, map <string, int>* supportedkeys,stack<State*>* states)
{
	this->states = states;
	this->supportedkeys = supportedkeys;
	this->window=window;
	this->quit = false;
	this->paused = false;
}

State::~State()
{

}

const bool& State::getquit() const
{
	return quit;
}

// void State::checkstate()
// {
// 	if(Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("Close"))))
// 	{
// 		this->quit = true;
// 	}
// }

void State::updatemousepos()
{
	this->mouseposscreen = Mouse::getPosition();
	this->mouseposwindow = Mouse::getPosition(*this->window);
	this->mouseposview = this->window->mapPixelToCoords(this->mouseposwindow);
	system ("cls");
	cout << "Mouse pos: " << this->mouseposview.x << " " << this->mouseposview.y << endl;
}

void State::pausestate()
{
	this->paused = true;
}

void State::unpausedstate()
{
	this->paused = false;
}

void State::endState()
{
	cout << "End state" << endl;
	this->quit = true;
}
