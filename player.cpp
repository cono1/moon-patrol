#include <iostream>

#include "player.h"

using namespace player;

Vehicle vehicle;

namespace player
{
	void initCar()
	{
		vehicle.isAlive = true;
		vehicle.collisionCarBox.x = 10;
		vehicle.collisionCarBox.y = static_cast<float> (GetScreenHeight() / 2 );
		vehicle.collisionCarBox.width= 100;
		vehicle.collisionCarBox.height= 100;
		vehicle.gravity = 100.0f;
		vehicle.speed = 50;
	}

	void drawCar()
	{
		DrawRectangle(static_cast<int>(vehicle.collisionCarBox.x), static_cast<int>(vehicle.collisionCarBox.y), static_cast<int>(vehicle.collisionCarBox.width), static_cast<int>(vehicle.collisionCarBox.height), DARKPURPLE);
	}

	void moveCarForward()
	{
		vehicle.collisionCarBox.x += 50 * GetFrameTime();
	}

	void moveCar()
	{
		if (IsKeyPressed(KEY_UP) && vehicle.collisionCarBox.y > GetScreenHeight() - 600)
		{
			vehicle.collisionCarBox.y -= 450000 * GetFrameTime();
		}

		if (IsKeyPressed(KEY_LEFT)) // y la esquina izquierda no sobrepasa el borde(?
		{
			vehicle.collisionCarBox.x -= 15000 * GetFrameTime();
		}

		if (IsKeyPressed(KEY_RIGHT))
		{
			vehicle.collisionCarBox.x += 15000 * GetFrameTime();
		}

		if(vehicle.collisionCarBox.x >= GetScreenWidth())
		{
			vehicle.collisionCarBox.x = 10;
		}
	}

	void attractCarToGround()
	{
		if (vehicle.collisionCarBox.y < GetScreenHeight() / 2)
		{
			vehicle.collisionCarBox.y += vehicle.gravity * GetFrameTime();
		}

		if (vehicle.collisionCarBox.y < 0)
		{
			vehicle.collisionCarBox.y += vehicle.collisionCarBox.height;
		}
	}
}
