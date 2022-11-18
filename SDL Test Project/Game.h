#pragma once
#include "InputManager.h"
#include "StarScape.h"
#include <SDL.h>

class Game
{
public:
	void Update();
	void Render(int r,int b,int g);
	bool IsGameRunning();
	void Initialise();
	void Uninitialise();

private:
	SDL_Window* game_window;
	SDL_Renderer* game_renderer;
	InputManager* game_inputmanager = new InputManager;
	StarScape* game_starscape;
};

