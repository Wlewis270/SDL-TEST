#include "Game.h"
#include <iostream>

void Game::Update()
{
	game_inputmanager->Update();

	if (game_inputmanager->GetKeyDown(SDLK_ESCAPE))
	{
		Uninitialise();
		SDL_Quit();
	}

	if (game_inputmanager->GetKeyDown(SDLK_UP))
	{
		Render(255, 0, 0);
	}
	if (game_inputmanager->GetKeyDown(SDLK_LEFT))
	{
		Render(0, 255, 0);
	}
	if (game_inputmanager->GetKeyDown(SDLK_RIGHT))
	{
		Render(0, 0, 255);
	}
	
}

void Game::Render(int r, int b, int g)
{
	SDL_SetRenderDrawColor(game_renderer, r, g, b, 255);
	SDL_RenderClear(game_renderer);
	SDL_RenderPresent(game_renderer);
}

bool Game::IsGameRunning()
{
    return true;
}

void Game::Initialise()
{
	if (SDL_Init(SDL_INIT_EVERYTHING != 0))
	{
		std::cout << "SDL Init failed";
		return;
	}
	
	game_window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_OPENGL);
	
	game_renderer = SDL_CreateRenderer(game_window, -1, 0);

	Render(255,0,0);
}

void Game::Uninitialise()
{
	SDL_DestroyRenderer(game_renderer);
	SDL_DestroyWindow(game_window);
}
