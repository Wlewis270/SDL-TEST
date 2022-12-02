#include <SDL.h>
#include "Game.h"
#include <iostream>
int main(int argc, char* argv[])
{

	srand(time(NULL));
	Game* game = Game::Get();

	game->Initialise();
	while (game->IsGameRunning() == true)
	{
		game->Update();
	}
	if (game->IsGameRunning() == false)
	{
		return 1;
	}
}

