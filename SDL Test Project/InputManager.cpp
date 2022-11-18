#include "InputManager.h"

InputManager::InputManager() : key_event(nullptr)
{
	key_event = new SDL_Event();
	for (int i = 0; i < 290; i++)
	{
		KEYS[i] = 0;
	}
}

bool InputManager::GetKeyUp(SDL_Keycode key)
{
	
	switch (key_event->type)
	{
	case SDL_KEYUP:
		if (key_event->key.keysym.sym == key)
		{
			return true;
		}

	default:
		return false;
	}
	
}

bool InputManager::GetKeyHeld(SDL_Keycode key)
{	
	SDL_Scancode scancode = SDL_GetScancodeFromKey(key);

	if (KEYS[scancode] == 1)
	{
		return true;
	}
	
	return false;
}

bool InputManager::GetKeyDown(SDL_Keycode key)
{
	switch (key_event->type)
	{
	case SDL_KEYDOWN:
		if (key_event->key.keysym.sym == key)
		{
			return true;
		}

	default:
		return false;
	}
	
}

void InputManager::Update()
{
	SDL_PollEvent(key_event);
	
	switch (key_event->type)
	{
	case SDL_KEYDOWN:
	{
		KEYS[key_event->key.keysym.scancode] = 1;
	}
	case SDL_KEYUP:
	{
		KEYS[key_event->key.keysym.scancode] = 0;
	}
	}
}
