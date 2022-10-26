#include <iostream>
#include "player.h"
using namespace player;

Car car;

namespace player
{
	void initCar()
	{
		car.pos.x = 10;
		car.pos.y = static_cast<float> (GetScreenHeight() / 2 - 50);
		car.size.x = 100;
		car.size.y = 100;
	}

	void drawCar()
	{
		DrawRectangleV(car.pos, car.size, DARKPURPLE);
	}

	void moveCarForward()
	{
		car.pos.x += 20 * GetFrameTime();
	}

	void moveCar()
	{
		if (IsKeyDown(KEY_UP))
		{
			car.pos.y = static_cast<float>(GetScreenHeight() / 2 - 200);
		}
		if (IsKeyDown(KEY_DOWN))
		{
			car.pos.y = static_cast<float>(GetScreenHeight() / 2 - 50);
		}
		if (IsKeyPressed(KEY_LEFT)) // y la esquina izquierda no sobrepasa el borde(?
		{
			car.pos.x -=  10000 * GetFrameTime();
		}
		if (IsKeyPressed(KEY_RIGHT))
		{
			car.pos.x += 10000 * GetFrameTime();
		}
	}
}
