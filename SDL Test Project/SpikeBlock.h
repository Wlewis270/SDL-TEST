#pragma once
#include <string>

class SDL_Rect;
class Visualisation;
class InputManager;
class SDL_Renderer;

class SpikeBlock
{
public:
	SpikeBlock();
	std::string Getname();
	void Initialise();
	void Uninitialise();
	void Render();
	void Update();
	SDL_Rect* GetLocation();
private:
	int image_id;
	SDL_Rect* spike_block_rect;
	Visualisation* spike_block_visualisation = nullptr;
};

