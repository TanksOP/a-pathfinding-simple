#include "GameLoop.h"

GameLoop::GameLoop()
{
}

void GameLoop::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return;
	}
	window = SDL_CreateWindow(
		"A* pathfinding",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		1024, 768,
		SDL_WINDOW_SHOWN
	);

	// Create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	map = new Map(this->renderer);
	map->init();

	player = new Player(this->renderer, map);
	player->init();
	return;
}

bool GameLoop::handleInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			int mx, my;
			SDL_GetMouseState(&mx, &my);
			player->handleInput(mx, my);
		}

	}

	return true;
}

void GameLoop::update()
{
	map->update();
	player->update();
}

void GameLoop::draw()
{
	SDL_RenderClear(renderer);

	map->draw();
	player->draw();

	SDL_RenderPresent(renderer);
	SDL_Delay(16);
}

void GameLoop::clean()
{
	map->clean();
	player->clean();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	delete map;
}
