#include "Player.h"
#include "Visualisation.h"
#include "SDL.h"
#include "InputManager.h"
Player::Player(InputManager* im)
{
	player_input_manager = im;
}

std::string Player::Getname()
{
	return "Player";
}

void Player::Initialise()
{
	player_visualisation = Visualisation::Get();
	player_rect = new SDL_Rect;
	player_rect->x = 100;
	player_rect->y = 100;
	player_rect->w = 64;
	player_rect->h = 64;

	image_id = player_visualisation->AddImage(".\\bitmaps\\testimage.bmp");
}

void Player::Uninitialise()
{
	delete player_rect;
}

void Player::Render()
{
	player_visualisation->DrawImage(image_id, player_rect);
}

void Player::Update()
{
	if(player_input_manager->GetKeyHeld(SDLK_RIGHT))
	{
		player_rect->x = player_rect->x + 5;
	}

	if (player_input_manager->GetKeyHeld(SDLK_LEFT))
	{
		player_rect->x = player_rect->x - 5;
	}

	if (player_input_manager->GetKeyHeld(SDLK_UP))
	{
		player_rect->y = player_rect->y - 5;
	}

	if (player_input_manager->GetKeyHeld(SDLK_DOWN))
	{
		player_rect->y = player_rect->y + 5;
	}
}

SDL_Rect* Player::GetLocation()
{
	return player_rect;
}


