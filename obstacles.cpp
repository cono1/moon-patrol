#include "obstacles.h"

#include <iostream>
#include <cmath>

using namespace obstacles;

Obstacle obstacle;
Rectangle collisionObstacleBox;
Rectangle aerealEnemy;

namespace obstacles
{
	void initObstacle()
	{
		obstacle.speed = 500;
		obstacle.waitTime = 0;
		collisionObstacleBox.x = static_cast<float> (GetScreenWidth());
		collisionObstacleBox.y = static_cast<float> (GetScreenHeight() / 2 + 85);
		collisionObstacleBox.width = 15;
		collisionObstacleBox.height = 15;

		aerealEnemy.x = 10;
		aerealEnemy.y = 200;
		aerealEnemy.width = 50;
		aerealEnemy.height = 50;
	}

	void drawObstacle()
	{
		DrawRectangle(static_cast<int>(collisionObstacleBox.x), static_cast<int>(collisionObstacleBox.y), static_cast<int>(collisionObstacleBox.width), static_cast<int>(collisionObstacleBox.height), YELLOW);
		DrawRectangle(static_cast<int>(aerealEnemy.x), static_cast<int>(aerealEnemy.y), static_cast<int>(aerealEnemy.width), static_cast<int>(aerealEnemy.height), YELLOW);
	}

	void moveObstacle()
	{
		obstacle.waitTime++;
		if (obstacle.waitTime > 800)
		{
			collisionObstacleBox.x -= obstacle.speed * GetFrameTime();
		}

		if (collisionObstacleBox.x < 0 && obstacle.waitTime > 10000)
		{
			collisionObstacleBox.x = static_cast<float> (GetScreenWidth());
			obstacle.waitTime = 0;
		}

		aerealEnemy.x += 10 * GetFrameTime(); //50  10
		aerealEnemy.y += 100 * sin(aerealEnemy.x) * GetFrameTime(); //200  1000
		
		if (aerealEnemy.x > GetScreenHeight())
		{
			aerealEnemy.x = static_cast<float> (GetScreenWidth());
		}
	}
}