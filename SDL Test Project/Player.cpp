#include "Player.h"
#include "Visualisation.h"
#include "SDL.h"
#include "InputManager.h"
#include "Game.h"

Player::Player(InputManager* im)
{
	ent_input_manager = im;
}

std::string Player::Getname()
{
	return "Player";
}

void Player::Initialise()
{
	ent_visualisation = Visualisation::Get();
	ent_rect = new SDL_Rect;
	ent_game = Game::Get();

	ent_rect->x = 100;
	ent_rect->y = 100;
	ent_rect->w = 64;
	ent_rect->h = 64;


	image_id = ent_visualisation->AddImage(".\\bitmaps\\testimage.bmp");
}


void Player::Update()
{

	int playerX = GetLocation()->x;
	int playerY = GetLocation()->y;
	
	if(ent_input_manager->GetKeyHeld(SDLK_RIGHT))
	{
		ent_rect->x = ent_rect->x + 5;
	}

	if (ent_input_manager->GetKeyHeld(SDLK_LEFT))
	{
		ent_rect->x = ent_rect->x - 5;
	}

	if (ent_input_manager->GetKeyHeld(SDLK_UP))
	{
		ent_rect->y = ent_rect->y - 5;
	}

	if (ent_input_manager->GetKeyHeld(SDLK_DOWN))
	{
		ent_rect->y = ent_rect->y + 5;
	}
	
	std::string player_collision = ent_game->CheckCollisions(this);

	if (player_collision == "Block")
	{
		ent_rect->x = playerX;
		ent_rect->y = playerY;
	}

	if (player_collision == "Spike block")
	{
		if (ent_rect->x = playerX + 5)
		{
			ent_rect->x = ent_rect->x - 10;
		}

		if (ent_rect->x = playerX - 5)
		{
			ent_rect->x = ent_rect->x + 10;
		}

		if (ent_rect->y = playerY + 5)
		{
			ent_rect->y = ent_rect->y - 10;
		}

		if (ent_rect->y = playerY - 5)
		{
			ent_rect->y = ent_rect->y + 10;
		}
	}
}
