#include "Player.h"

void Player::update()
{
		if (SDL_GetTicks() - lastUpdate > 500) {
			lastUpdate = SDL_GetTicks();
			if (selectionX >= 0 && selectionY >= 0) {
				Node player;
				player.x = playerX;
				player.y = playerY;
				Node dest;
				dest.x = selectionX;
				dest.y = selectionY;
				std::vector<Node> path = aStar(map->MAP_DATA, player, dest);
				if (path.size() > 1) {
					playerX = path[1].x;
					playerY = path[1].y;
				}
			}
		}
}
