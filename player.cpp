#include <iostream>
#include "player.h"
using namespace player;

Vehicle vehicle;

namespace player
{
	void initCar()
	{
		vehicle.isAlive = true;
		vehicle.collidingCarBox.x = 10;
		vehicle.collidingCarBox.y = static_cast<float> (GetScreenHeight() / 2 );
		vehicle.collidingCarBox.width= 100;
		vehicle.collidingCarBox.height= 100;
		vehicle.gravity = 90.0f;
		vehicle.speed = 10000;
	}

	void drawCar()
	{
		DrawRectangle(static_cast<int>(vehicle.collidingCarBox.x), static_cast<int>(vehicle.collidingCarBox.y), static_cast<int>(vehicle.collidingCarBox.width), static_cast<int>(vehicle.collidingCarBox.height), DARKPURPLE);
	}

	void moveCarForward()
	{
		vehicle.collidingCarBox.x += 20 * GetFrameTime();
	}

	void moveCar()
	{
		if (IsKeyPressed(KEY_UP))
		{
			vehicle.collidingCarBox.y -= 200000 * GetFrameTime();
		}
		if (IsKeyDown(KEY_DOWN))
		{
			//vehicle.collidingCarBox.y = static_cast<float>(GetScreenHeight() / 2 - 50);
		}
		if (IsKeyPressed(KEY_LEFT)) // y la esquina izquierda no sobrepasa el borde(?
		{
			vehicle.collidingCarBox.x -= vehicle.speed * GetFrameTime();
		}
		if (IsKeyPressed(KEY_RIGHT))
		{
			vehicle.collidingCarBox.x += vehicle.speed * GetFrameTime();
		}
	}

	void attractCarToGround()
	{
		//while la pos en y no sobrepase la calle(?
		if (vehicle.collidingCarBox.y < GetScreenHeight() / 2)
		{
			vehicle.collidingCarBox.y += vehicle.gravity * GetFrameTime();
		}
		if (vehicle.collidingCarBox.y < 0)
		{
			vehicle.collidingCarBox.y += vehicle.collidingCarBox.height;
		}
	}
}
