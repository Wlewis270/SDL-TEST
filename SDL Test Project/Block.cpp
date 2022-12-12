#include "Block.h"
#include "Visualisation.h"
#include "SDL.h"


Block::Block()
{
}

std::string Block::Getname()
{
	return "Block";
}

void Block::Initialise()
{
	ent_visualisation = Visualisation::Get();
	ent_rect = new SDL_Rect;

	ent_rect->x = rand() % 1280;
	ent_rect->y = rand()% 720;
	ent_rect->w = 64;
	ent_rect->h = 64;

	image_id = ent_visualisation->AddImage(".\\bitmaps\\abstract1.bmp");
}


