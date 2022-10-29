#include <iostream>
#include <raylib.h>
#include "game.h"
#include "player.h"
#include "obstacles.h"

using namespace player;

extern Rectangle car;
extern Rectangle obstacle;
extern Vehicle vehicle;

namespace game
{
	void checkCollisions()
	{
		if (CheckCollisionRecs(car, obstacle))
		{
			vehicle.isAlive = false;
		}
	}

	void showFinalMessage()
	{
		if (!vehicle.isAlive)
		{
			DrawText("You loose", 300, 250, 90, RAYWHITE);
		}
	}
}