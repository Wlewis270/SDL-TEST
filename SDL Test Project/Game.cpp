#include "Game.h"
#include <iostream>
#include "Visualisation.h"
#include "InputManager.h"

void Game::Update()
{
	game_inputmanager->Update();

	if (game_inputmanager->GetKeyDown(SDLK_ESCAPE))
	{
		Uninitialise();
		SDL_Quit();
	}
}

void Game::Render()
{
	SDL_RenderClear(game_renderer);
	game_visualisation->DrawImage(image_id, game_rect);
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

	game_inputmanager = new InputManager;
	
	game_visualisation = new Visualisation(game_renderer);

	game_rect = new SDL_Rect;
	
	game_rect->x = 100;
	game_rect->y = 100;
	game_rect->w = 64;
	game_rect->h = 64;

	image_id = game_visualisation->AddImage(".\\bitmaps\\testimage.bmp");

	Render();
}

void Game::Uninitialise()
{
	SDL_DestroyRenderer(game_renderer);
	SDL_DestroyWindow(game_window);
	delete game_visualisation;
}
