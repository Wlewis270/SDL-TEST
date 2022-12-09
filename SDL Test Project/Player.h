#pragma once
#include <string>

class SDL_Rect;
class Visualisation;
class InputManager;
class SDL_Renderer;
class Block;
class Game;

class Player
{
public:
	Player(InputManager* im);
	std::string Getname();
	void Initialise();
	void Uninitialise();
	void Render();
	void Update();
	SDL_Rect* GetLocation();
private:
	int image_id;
	SDL_Rect* player_rect;
	InputManager* player_input_manager;
	Visualisation* player_visualisation = nullptr;
	Game* player_game = nullptr;
};

