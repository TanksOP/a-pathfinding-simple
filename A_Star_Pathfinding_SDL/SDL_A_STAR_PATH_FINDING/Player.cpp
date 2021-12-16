#include "Player.h"

void Player::update()
{
		if (SDL_GetTicks() - lastUpdate > 500) {
			lastUpdate = SDL_GetTicks();


			if (selectionX >= 0 && selectionY >= 0) {
				// creates a node point for the players current position
				Node player;
				player.x = playerX;
				player.y = playerY;
				// creates a node point for where the desired destiation is
				Node dest;
				dest.x = selectionX;
				dest.y = selectionY;
				// creating a vector of nodes that form tha path from the player to the dest
				std::vector<Node> path = aStar(map->MAP_DATA, player, dest);
				
				// when there is a anouter node in path, move the player to the position of the next node
				
				if (path.size() > 1) {
					std::cout << "Move" << std::endl;
					playerX = path[1].x;
					playerY = path[1].y;
				}
			}
			}
		}
		
		
