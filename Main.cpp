#include <iostream>
#include "Game.h"

int main()
{
	//initialize randome Seed
	srand(static_cast<unsigned>(time(NULL)));
	game game;
	//Game Loop
	game.run();

	return 0;
}
