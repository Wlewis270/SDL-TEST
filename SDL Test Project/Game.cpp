#include "Game.h"
#include <iostream>
#include "Visualisation.h"
#include "InputManager.h"

Game* Game::s_instance = nullptr;

Game* Game::Get()
{
	if (s_instance = nullptr)
	{
		Game* s_instance = new Game;
		return s_instance;
	}
}

void Game::Update()
{
	game_inputmanager->Update();

	if (game_inputmanager->GetKeyDown(SDLK_ESCAPE))
	{
		Uninitialise();
		SDL_Quit();
	}

	if (game_inputmanager->GetKeyHeld(SDLK_RIGHT))
	{
		player_rect->x = player_rect->x + 1;
	}

	if (game_inputmanager->GetKeyHeld(SDLK_LEFT))
	{
		player_rect->x = player_rect->x - 1;
	}

	if (game_inputmanager->GetKeyHeld(SDLK_UP))
	{
		player_rect->y = player_rect->y - 1;
	}

	if (game_inputmanager->GetKeyHeld(SDLK_DOWN))
	{
		player_rect->y = player_rect->y + 1;
	}

	Render();
}

void Game::Render()
{
	SDL_RenderClear(game_renderer);
	
	game_visualisation->DrawImage(player_image_id, player_rect);
	
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

	player_rect = new SDL_Rect;
	
	player_rect->x = 100;
	player_rect->y = 100;
	player_rect->w = 64;
	player_rect->h = 64;

	player_image_id = game_visualisation->AddImage(".\\bitmaps\\testimage.bmp");



	Render();
}

void Game::Uninitialise()
{
	SDL_DestroyRenderer(game_renderer);
	SDL_DestroyWindow(game_window);
	delete game_visualisation;
	delete player_rect;
}
