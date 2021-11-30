#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Map.h"
#include "Player.h"

class GameLoop {

public:
	GameLoop();
	void init();
	bool handleInput();
	void update();
	void draw();
	void clean();
private:
	SDL_Window * window;
	SDL_Renderer * renderer;
	Map * map;
	Player * player;
};