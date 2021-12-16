#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "AStarSearch.h"
#include "Map.h"

class Player {
public:
	Player(SDL_Renderer * renderer, Map * map) {
		this->renderer = renderer;
		this->map = map;

	}
	void init() {
		SDL_Surface * surface = IMG_Load("cache/Player/player_01.png");
		this->player = SDL_CreateTextureFromSurface(this->renderer, surface);
		SDL_FreeSurface(surface);
		surface = IMG_Load("cache/Environment/environment_03.png");
		this->selectionTile = SDL_CreateTextureFromSurface(this->renderer, surface);
		SDL_FreeSurface(surface);
	}
	//just x and y position of mouse, only called if mouse is pressed
	void handleInput(int x, int y) {
		selectionX = x / 32;
		selectionY = y / 32;
	}
	void update();
	void UpdatePath();
	void draw() {
		SDL_FRect dest = { selectionX * 32, selectionY * 32, 32, 32 };
		SDL_RenderCopyF(renderer, selectionTile, 0, &dest);
		dest = { playerX * 32, playerY * 32, 32, 32 };
		SDL_RenderCopyF(renderer, player, 0, &dest);
		
	}
	void clean() { SDL_DestroyTexture(player); SDL_DestroyTexture(selectionTile); }
private:
	SDL_Renderer * renderer;
	SDL_Texture * player;
	Map * map;
	SDL_Texture * selectionTile;
	int selectionX = -1, selectionY = -1;
	float playerX = 1, playerY = 1;
	unsigned int lastUpdate = 0;

	std::vector<Node> path;
	
	bool playerMoving = false;
	float speed = 1.f/20.f;
};