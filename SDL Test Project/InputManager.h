#pragma once
#include <SDL.h>
class InputManager
{
public:
	InputManager();
	bool GetKeyUp(SDL_Keycode key);
	bool GetKeyHeld(SDL_Keycode key);
	bool GetKeyDown(SDL_Keycode key);
	void Update();
	
private:
	SDL_Event* key_event;
	int KEYS[290];
};

