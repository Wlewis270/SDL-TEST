#pragma once
#include <string>
#include "Entity.h"

class SDL_Rect;
class Visualisation;
class InputManager;
class SDL_Renderer;
class Block;
class Game;

class Player : public Entity
{
public:
	Player(InputManager* im);
	std::string Getname();
	void Initialise();
	void Update();
private:
	int image_id;
	SDL_Rect* ent_rect;
	Visualisation* ent_visualisation = nullptr;
	InputManager* ent_input_manager;
	Game* ent_game = nullptr;
};

