#pragma once
#include <string>

class SDL_Rect;
class Visualisation;
class InputManager;
class SDL_Renderer;

class Block
{
public:
	Block();
	std::string Getname();
	void Initialise();
	void Uninitialise();
	void Render();
	void Update();
	SDL_Rect* GetLocation();
private:
	int image_id;
	SDL_Rect* block_rect;
	InputManager* block_input_manager;
	Visualisation* block_visualisation = nullptr;
};

