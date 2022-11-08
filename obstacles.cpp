#include "obstacles.h"

#include <iostream>
#include <cmath>

using namespace obstacles;

Rectangle obstacle;
Rectangle aerealEnemy;

namespace obstacles
{
	void initObstacle()
	{
		obstacle.x = static_cast<float> (GetScreenWidth());
		obstacle.y = static_cast<float> (GetScreenHeight() / 2 + 85);
		obstacle.width = 15;
		obstacle.height = 15;

		aerealEnemy.x = 10;
		aerealEnemy.y = 200;
		aerealEnemy.width = 50;
		aerealEnemy.height = 50;
	}

	void drawObstacle()
	{
		DrawRectangle(static_cast<int>(obstacle.x), static_cast<int>(obstacle.y), static_cast<int>(obstacle.width), static_cast<int>(obstacle.height), YELLOW);
		DrawRectangle(static_cast<int>(aerealEnemy.x), static_cast<int>(aerealEnemy.y), static_cast<int>(aerealEnemy.width), static_cast<int>(aerealEnemy.height), YELLOW);
	}

	void moveObstacle()
	{
		obstacle.x -= 100 * GetFrameTime();
		if (obstacle.x < 0)
		{
			obstacle.x = static_cast<float> (GetScreenWidth());
		}

		aerealEnemy.x += 10 * GetFrameTime(); //50  10
		aerealEnemy.y += 100 * sin(aerealEnemy.x) * GetFrameTime(); //200  1000
		
		if (aerealEnemy.x > GetScreenHeight())
		{
			aerealEnemy.x = static_cast<float> (GetScreenWidth());
		}
	}
}