#pragma once
#include <string>
#include "Entity.h"
class SDL_Rect;
class Visualisation;
class InputManager;
class SDL_Renderer;

class SpikeBlock : public Entity
{
public:
	SpikeBlock();
	std::string Getname();
	void Initialise();
private:
	int image_id;
	SDL_Rect* ent_rect;
	Visualisation* ent_visualisation = nullptr;
};

