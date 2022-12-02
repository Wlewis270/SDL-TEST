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
	block_visualisation = Visualisation::Get();
	block_rect = new SDL_Rect;

	block_rect->x = rand() % 1280;
	block_rect->y = rand()% 720;
	block_rect->w = 64;
	block_rect->h = 64;

	image_id = block_visualisation->AddImage(".\\bitmaps\\abstract1.bmp");
}

void Block::Uninitialise()
{
	delete block_rect;
}

void Block::Render()
{
	block_visualisation->DrawImage(image_id, block_rect);
}

void Block::Update()
{
}

SDL_Rect* Block::GetLocation()
{
	return block_rect;
}
