#include "Game.h"
#include <iostream>
#include "Visualisation.h"
#include "InputManager.h"
#include "Player.h"
#include "Block.h"

Game* Game::s_instance = nullptr;

Game* Game::Get()
{
	if (s_instance == nullptr)
	{
		Game* s_instance = new Game;
		return s_instance;
	}

	return s_instance;
}

void Game::Update()
{
	game_inputmanager->Update();
	game_player->Update();
	
	if (CheckCollisions(game_player) == "Block")
	{
		SDL_SetRenderDrawColor(game_renderer, 0, 255, 0, 255);
	}

	if (game_inputmanager->GetKeyDown(SDLK_ESCAPE))
	{
		Uninitialise();
		SDL_Quit();
		gamerunning = false;
		return;
	}

	Render();
}

void Game::Render()
{
	SDL_RenderClear(game_renderer);
	
	SDL_SetRenderDrawColor(game_renderer, 0, 0, 255, 255);

	for (int i = 0; i < 3; i++)
	{
		game_block[i]->Render();
	}
	game_player->Render();
	SDL_RenderPresent(game_renderer);

	SDL_Delay(1000 / 60);
}

bool Game::IsGameRunning()
{
	return gamerunning == true;
}

void Game::Initialise()
{
	gamerunning = true;
	
	if (SDL_Init(SDL_INIT_EVERYTHING != 0))
	{
		std::cout << "SDL Init failed";
		return;
	}
	
	game_window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_OPENGL);
	
	game_renderer = SDL_CreateRenderer(game_window, -1, 0);

	game_inputmanager = new InputManager;

	game_visualisation = Visualisation::Initialise(game_renderer);

	game_player = new Player(game_inputmanager);
	game_player->Initialise();

	for (int i = 0; i < 3; i++)
	{
		game_block[i] = new Block;
		game_block[i]->Initialise();
	}

	Render();
}

void Game::Uninitialise()
{
	SDL_DestroyRenderer(game_renderer);
	SDL_DestroyWindow(game_window);
	game_player->Uninitialise();
	
	delete game_player;
	
	delete game_inputmanager;
	
	for (int i = 0; i < 3; i++)
	{
		game_block[i]->Uninitialise();
	}
	
	for (int i = 0; i < 3; i++)
	{
		delete game_block[i];
	}
}

std::string Game::CheckCollisions(Player* player)
{	
	bool collision_checked = false;

	game_player_rect = player->GetLocation();
	
	while (collision_checked == false)
	{
		for (int i = 0; i < 3; i++)
		{
			game_block_rect = game_block[i]->GetLocation();

			if (TestCollision(player, game_block[i]) == true)
			{
				return game_block[i]->Getname();
			}
		}
		return "";
	}
}


bool Game::TestCollision(Player* player, Block* block)
{
	int playerminX = game_player_rect->x;
	int playerminY = game_player_rect->y;
	int playermaxX = game_player_rect->x + game_player_rect->w;
	int playermaxY = game_player_rect->y + game_player_rect->h;
	
	int blockminX = game_block_rect->x;
	int blockminY = game_block_rect->y;
	int blockmaxX = game_block_rect->x + game_block_rect->w;
	int blockmaxY = game_block_rect->y + game_block_rect->h;

	if (playerminY > blockmaxY)
	{
		return false;
	}

	if (playermaxY < blockminY)
	{
		return false;
	}

	if (blockminX > playermaxX)
	{
		return false;
	}

	if (blockmaxX < playerminX)
	{
		return false;
	}

	return true;
	
}

Game::Game()
{
}
