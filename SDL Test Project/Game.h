#pragma once
#include <vector>
#include <string>
class InputManager;
class Visualisation;
class SDL_Window;
class SDL_Renderer;
class SDL_Rect;
class Player;
class Block;

class Game
{
public:
	static Game* Get();
	void Update();
	void Render();
	bool IsGameRunning();
	void Initialise();
	void Uninitialise();
	std::string CheckCollisions(Player* player);
	bool TestCollision(Player* player, Block* block);

private:
	Game();
	Game(const Game&) = delete;
	static Game* s_instance;

	SDL_Window* game_window;
	SDL_Renderer* game_renderer;
	InputManager* game_inputmanager;
	Visualisation* game_visualisation;
	Player* game_player;
	SDL_Rect* game_player_rect;
	Block* game_block[3];
	SDL_Rect* game_block_rect;
	bool gamerunning;
	
	

};

