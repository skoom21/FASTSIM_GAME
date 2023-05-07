#include "GameState.h"

void GameState::initfont()
{
	if (!this->font.loadFromFile("content/Fonts/Dosis-Light.ttf"))
	{
		cout << "ERROR::MAINMENUSTATE::COULD NOT LOAD FONT" << endl;
	}
}

void GameState::initPlayer()
{
	player = new Player(0, 0, this->textures["PLAYER_SHEET"]);
}

void GameState::initTextures()
{
	Texture temp;
	temp.loadFromFile("content/Textures/Character.png");
	this->textures["PLAYER_SHEET"] = temp;
	temp.loadFromFile("content/Textures/Background.png");
	this->textures["BACKGROUND"] = temp;

}
void GameState::initkeybinds()
{
	ifstream ifs("Config/gamestate_keybinds.ini");
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


void GameState::initWorldBackground()
{
	this->WorldBackground.setTexture(this->textures["BACKGROUND"]);
}

GameState::GameState(RenderWindow* window, map<string, int>* supportedkeys, stack<State*>* states) :State(window, supportedkeys, states)
{
	this->pmenu = new PauseMenu(*this->window, this->font);
	this->initfont();
	this->initkeybinds();
	this->initTextures();
	this->initPlayer();
	this->initWorldBackground();
}


GameState::~GameState()
{
	delete this->player;
}

void GameState::updateinput(const float& dt)
{
	//Update player input
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("Move_Left"))))
	{
		this->player->movement(dt, -1.f, 0.f);
		this->player->updateAnimation(dt, 1);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("Move_Right"))))
	{
		this->player->movement(dt, 1.f, 0.f);
		this->player->updateAnimation(dt, 2);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("Move_Up"))))
	{
		this->player->movement(dt, 0.f, -1.f);
		this->player->updateAnimation(dt, 3);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("Move_Down"))))
	{
		this->player->movement(dt, 0.f, 1.f);
		this->player->updateAnimation(dt, 0);
	}

}

void GameState::updatePausedInput()
{
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("Close"))))
	{
		if (!this->paused)
		this->pausestate();
		else
		this->unpausedstate();
	}
}

// void GameState::updateWindowBoundsCollision(RenderTarget* target)
// {
// 	//Left
// 	if (this->player->getbounds().left < 0.f)
// 	{
// 		this->player->setpos(Vector2f(0.f, this->player->getbounds().top));
// 	}
// 	//Right
// 	else if (this->player->getbounds().left + this->player->getbounds().width > this->window->getSize().x)
// 	{
// 		this->player->setpos(Vector2f(target->getSize().x - this->player->getbounds().width, this->player->getbounds().top));
// 	}
// 	//Top
// 	if (this->player->getbounds().top < 0.f)
// 	{
// 		this->player->setpos(Vector2f(this->player->getbounds().left, 0.f));
// 	}
// 	//Bottom
// 	else if (this->player->getbounds().top + this->player->getbounds().height > target->getSize().y)
// 	{
// 		this->player->setpos(Vector2f(this->player->getbounds().left, target->getSize().y - this->player->getbounds().height));
// 	}
// }


void GameState::update(const float& dt, RenderTarget* target)
{
	this->updateinput(dt);
	this->updatemousepos();
	this->updatePausedInput();
	if(!this->paused )//Unpaused update
	{
		this->player->update(dt);
		this->player->updateWindowBoundColision(target);
	}
	else
	{
		//Pause menu update
		this->pmenu->update(mouseposview);
	}
}
void GameState::render(RenderTarget* target)
{
	if(!target)
	{
		target = this->window;
	}
	target->draw(WorldBackground);
	this->player->render(*target);

	if(this->paused)//Pause menu render
	{
		//Render pause menu
		this->pmenu->render(*target);
	}
}
