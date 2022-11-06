#pragma once
#include "raylib.h"

namespace player
{
	struct Vehicle
	{
		Rectangle collisionCarBox;
		bool isAlive;
		int speed;
		float gravity;
		float upMovement;
	};
	void initCar();
	void drawCar();
	void moveCarForward();
	void moveCar();
	void attractCarToGround();
}
	