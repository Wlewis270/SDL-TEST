#pragma once
#include <string>
#include "Entity.h"
class SDL_Rect;
class Visualisation;
class SDL_Renderer;

class Block : public Entity
{
public:
	Block();
	std::string Getname();
	void Initialise();
	void Uninitialise();
private:
	int image_id;
	SDL_Rect* ent_rect;
	Visualisation* ent_visualisation = nullptr;
};

