#pragma once

class InputManager;
class Visualisation;
class SDL_Window;
class SDL_Renderer;
class SDL_Rect;


class Game
{
public:
	static Game* Get();
	void Update();
	void Render();
	bool IsGameRunning();
	void Initialise();
	void Uninitialise();

private:
	Game();
	Game(const Game&);
	static Game* s_instance;
	SDL_Window* game_window;
	SDL_Renderer* game_renderer;
	InputManager* game_inputmanager;
	Visualisation* game_visualisation;
	SDL_Rect* player_rect;
	int player_image_id;
};

