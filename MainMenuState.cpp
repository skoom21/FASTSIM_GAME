#include "MainMenuState.h"

void MainMenuState::initVariables()
{
}

void MainMenuState::initBackground()
{
	this->background.setSize(Vector2f(static_cast<float>(this->window->getSize().x), static_cast<float>(this->window->getSize().y)));
	if (!this->backgroundTexture.loadFromFile("content/Textures/MainmenuBackground.png"))
	{
		cout << "ERROR::MAINMENUSTATE::FAILED TO LOAD BACKGROUND TEXTURE" << endl;
	}
	this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("content/Fonts/Dosis-Light.ttf"))
	{
		cout << "ERROR::MAINMENUSTATE::COULD NOT LOAD FONT" << endl;
	}
}

void MainMenuState::initkeybinds()
{
	ifstream ifs("Config/mainmenustate_keybinds.ini");
	if (ifs.is_open())
	{
		string key = "";
		string key2 = "";
		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedkeys->at(key2);
		}
	}
	ifs.close();

	// this->keybinds["Close"]= this->supportedkeys->at("Escape");
	// this->keybinds["Move_Left"] = this->supportedkeys->at("A");
	// this->keybinds["Move_Right"] = this->supportedkeys->at("D");
	// this->keybinds["Move_Up"] = this->supportedkeys->at("W");
	// this->keybinds["Move_Down"] = this->supportedkeys->at("S");
}

void MainMenuState::initButtons()
{
	//initializes buttons accoriding to there size postion and color
	this->buttons["GAME_STATE"] = new Button(525, 185, 837, 198, Color(70, 70, 70, 200), Color(150, 150, 150, 255), Color(20, 20, 20, 200), &this->font, "New Game");
	this->buttons["SETTINGS_STATE"] = new Button(525, 185, 837, 383, Color(70, 70, 70, 200), Color(150, 150, 150, 255), Color(20, 20, 20, 200), &this->font, "Settings");
	this->buttons["EXIT_STATE"] = new Button(525, 185, 837, 568, Color(70, 70, 70, 200), Color(150, 150, 150, 255), Color(20, 20, 20, 200), &this->font, "Exit");
}

MainMenuState::MainMenuState(RenderWindow* window, map<string, int>* supportedkeys, stack<State*>* states) :
	State(window, supportedkeys, states)
{
	this->initFonts();
	this->initkeybinds();
	this->initVariables();
	this->initBackground();
	this->initButtons();
}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}


void MainMenuState::updateinput(const float& dt)
{
	cout << dt << endl;
}

void MainMenuState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mouseposview);
	}
	//NEW GAME
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		this->states->push(new GameState(this->window, this->supportedkeys, this->states));
	}
	//QUIT
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->endState();
	}
}

void MainMenuState::update(const float& dt, RenderTarget* target)
{
	if (!target)
		target = this->window;
	this->updateinput(dt);
	this->updateButtons();
	this->updatemousepos();
}

void MainMenuState::renderButtons(RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void MainMenuState::render(RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->draw(this->background);
	this->renderButtons(*target);
}
