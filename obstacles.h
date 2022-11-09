#pragma once
#include "raylib.h"

namespace obstacles
{
	struct Obstacle
	{
		float speed;
		int waitTime;
	};
	void initObstacle();
	void drawObstacle();
	void moveObstacle();
}