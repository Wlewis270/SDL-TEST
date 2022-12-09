#include "SpikeBlock.h"
#include "Visualisation.h"
#include "SDL.h"

SpikeBlock::SpikeBlock()
{
}

std::string SpikeBlock::Getname()
{
	return "Spike block";
}

void SpikeBlock::Initialise()
{
	spike_block_visualisation = Visualisation::Get();
	spike_block_rect = new SDL_Rect;

	spike_block_rect->x = rand() % 1280;
	spike_block_rect->y = rand() % 720;
	spike_block_rect->w = 64;
	spike_block_rect->h = 64;

	image_id = spike_block_visualisation->AddImage(".\\bitmaps\\abstract2.bmp");
}

void SpikeBlock::Uninitialise()
{
	delete spike_block_rect;
}

void SpikeBlock::Render()
{
	spike_block_visualisation->DrawImage(image_id, spike_block_rect);
}

void SpikeBlock::Update()
{
}

SDL_Rect* SpikeBlock::GetLocation()
{
	return spike_block_rect;
}
