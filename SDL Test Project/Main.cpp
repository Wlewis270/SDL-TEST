#include <SDL.h>
#include "Game.h"


int main(int argc, char* argv[])
{
	Game* game = new Game();
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
