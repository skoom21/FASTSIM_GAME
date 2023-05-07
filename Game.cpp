#include "Game.h"

void game::initstates()
{
	this->states.push(new MainMenuState(this->window, &supportedkeys, &states));
}

void game::initkeybinds()
{
	ifstream ifs("Config/supportedkeys.ini");
	if (ifs.is_open())
	{
		string key = "";
		int key_value = 0;
		while (ifs >> key >> key_value)
		{
			this->supportedkeys[key] = key_value;
		}
	}
}

// void game::initenimies()
// {
// 	this->Enemy.setSize(Vector2f(50.f, 50.f));
// 	this->Enemy.setScale(Vector2f(0.5f, 0.5f));
// 	this->Enemy.setFillColor(Color::Green);
// 	this->Enemy.setPosition(50.f, 50.f);
// }

void game::initvars()
{
	this->window = nullptr;
	this->fullscreen = false;
	this->dt = 0.f;

}

void game::initwindow()
{
	//Creates an sfml window by using options from window.ini file
	ifstream ifs("Config/Window.ini");
	this->videomodes = VideoMode::getFullscreenModes();
	string title = "None";
	VideoMode window_bounds= VideoMode::getDesktopMode();
	unsigned framerate_limit = 120;
	unsigned antialiasing_level = 0;
	bool fullscreen = false;
	bool veritcal_sync_enabled = false;

	if (ifs.is_open())
	{
		getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> fullscreen;
		ifs >> framerate_limit;
		ifs >> veritcal_sync_enabled;
		ifs >> antialiasing_level;
	}
	else
	{
		cout << "ERROR::GAME::INITWINDOW::Failed to load window.ini file" << endl;
	}

	ifs.close();
	this->fullscreen = fullscreen;
	this->window_settings.antialiasingLevel = antialiasing_level;
	if(this->fullscreen)
		this->window = new RenderWindow(window_bounds, title, Style::Fullscreen, window_settings);
	else
		this->window = new RenderWindow(window_bounds, title, Style::Titlebar | Style::Close, window_settings);

	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(veritcal_sync_enabled);
}

game::game()
{
	this->initvars();
	this->initwindow();
	this->initkeybinds();
	this->initstates();
	// this->initenimies();

}

game::~game()
{
	delete this->window;

	while(this->states.empty() == false)
	{
		delete this->states.top();
		this->states.pop();
	}
}


void game::run()
{
	while (this->window->isOpen())
	{
		this->updatedt();
		this->update();
		this->render();
	}

}

/*
void game::updateenemy()
{
	//spawn the enemy and set the timer to zero
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			//spawn the enemy and reset the timer
			this->spawnenemy();
			this->enemySpawnTimer = 0.f;
		}
		else
			this->enemySpawnTimer += 1.f;
	}
	//Move & Update the Enemy

	for (unsigned int i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i].move(0.f, 5.f);

		//if the enemy is out of the screen
		if (this->enemies[i].getPosition().y > this->window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);
			this->health -= 1;
			cout << "Health: " << this->health << endl;
			if (health == 0)
			{
				this->endgame = true;
			}
		}
	}
	//if the enemy is clicked
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (mousehold == false)
		{
			this->mousehold = true;
			bool deleted = false;
			for (unsigned int i = 0; i < this->enemies.size() && deleted == false; i++)
			{
				if (this->enemies[i].getGlobalBounds().contains(this->mouseposview))
				{
					deleted = true;
					this->enemies.erase(this->enemies.begin() + i);
					this->points += 1;
					cout << this->points << endl;
				}
			}
		}
	}
	else
	{
		this->mousehold = false;
	}
}
*/

bool game::getwindowisopen()
{
	return window->isOpen();
}

void game::endapplication()
{
	cout << "Ending Application" << endl;
}

// void game::updateCollision()
// {
// 	//Check Collision
// 	for(size_t i = 0; i < this->balls.size(); i++)
// 	{
// 		if(this->player.getShape().getGlobalBounds().intersects(this->balls[i].getShape().getGlobalBounds()))
// 		{
// 			//Check Ball Type
// 			switch(this->balls[i].gettype())
// 			{
// 				case balltypes::DEFAULT:
// 					this->points+=1;
// 					break;
// 				case balltypes::DAMAGING:
// 					this->player.takeDamage(1);
// 					this->points-=1;
// 					break;
// 				case balltypes::HEALING:
// 					this->player.gainHealth(1);
// 					break;
// 				default:
// 					break;
// 			}
// 			if(this->player.getHP()==0)
// 			{
// 				this->endgame = true;
// 			}
// 			//Add points
// 			//Erase Ball
// 			this->balls.erase(this->balls.begin() + i);
// 		}
// 	}
// }


void game::updateEvents()
{
	while (window->pollEvent(ev))
	{
		switch (ev.type)
		{
			case Event::Closed:
				window->close();
				break;
			// case Event::KeyPressed:
			// 	if (ev.key.code == Keyboard::Escape)
			// 		window->close();
			// 	break;
			default:
				break;
		}
	}
}

void game::render()
{
	window->clear();
	if(!this->states.empty())
		this->states.top()->render(this->window);

	window->display();
}


void game::updatedt()
{
	this->dt = this->clock.restart().asSeconds();
}

void game::update()
{
	this->updateEvents();
	if(!this->states.empty())
	{
		this->states.top()->update(this->dt,this->window);
		if(this->states.top()->getquit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	else
	{
		this->endapplication();
		this->window->close();
	}
	//this->updateText();
	// this->player.update(this->window);
	// this->updateCollision();
}

