#pragma once

class InputManager;
class Visualisation;
class SDL_Window;
class SDL_Renderer;
class SDL_Rect;


class Game
{
public:
	void Update();
	void Render();
	bool IsGameRunning();
	void Initialise();
	void Uninitialise();

private:
	SDL_Window* game_window;
	SDL_Renderer* game_renderer;
	InputManager* game_inputmanager;
	Visualisation* game_visualisation;
	SDL_Rect* game_rect;
	int image_id;
};

