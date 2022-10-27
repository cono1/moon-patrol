#include <iostream>
#include <raylib.h>
#include "game.h"
#include "player.h"
#include "obstacles.h"

extern Rectangle car;
extern Rectangle obstacle;

namespace game
{
	void checkCollisions()
	{
		if (CheckCollisionRecs(car, obstacle))
		{
			std::cout << "colision\n";
		}
	}
}