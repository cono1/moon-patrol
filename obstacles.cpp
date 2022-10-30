#include "obstacles.h"
using namespace obstacles;

Rectangle obstacle;

namespace obstacles
{
	void initObstacle()
	{
		obstacle.x = static_cast<float> (GetScreenWidth());
		obstacle.y = static_cast<float> (GetScreenHeight() / 2 + 50);
		obstacle.width = 15;
		obstacle.height = 15;
	}

	void drawObstacle()
	{
		DrawRectangle(obstacle.x, obstacle.y, obstacle.width, obstacle.height, YELLOW);
	}

	void moveObstacle()
	{
		obstacle.x -= 100 * GetFrameTime();
		if (obstacle.x < 0)
		{
			obstacle.x = static_cast<float> (GetScreenWidth());
		}
	}
}