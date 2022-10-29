#include <iostream>
#include "player.h"
using namespace player;

Rectangle car;
Vehicle vehicle;

namespace player
{
	void initCar()
	{
		vehicle.isAlive = true;
		car.x = 10;
		car.y = static_cast<float> (GetScreenHeight() / 2 - 50);
		car.width= 100;
		car.height= 100;
	}

	void drawCar()
	{
		DrawRectangle(car.x, car.y, car.width, car.height, DARKPURPLE);
	}

	void moveCarForward()
	{
		car.x += 20 * GetFrameTime();
	}

	void moveCar()
	{
		if (IsKeyDown(KEY_UP))
		{
			car.y = static_cast<float>(GetScreenHeight() / 2 - 200);
		}
		if (IsKeyDown(KEY_DOWN))
		{
			car.y = static_cast<float>(GetScreenHeight() / 2 - 50);
		}
		if (IsKeyPressed(KEY_LEFT)) // y la esquina izquierda no sobrepasa el borde(?
		{
			car.x -=  10000 * GetFrameTime();
		}
		if (IsKeyPressed(KEY_RIGHT))
		{
			car.x += 10000 * GetFrameTime();
		}
	}
}
