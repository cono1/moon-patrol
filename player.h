#pragma once
#include <raylib.h>

namespace player
{
	struct Vehicle
	{
		Rectangle collidingCarBox;
		bool isAlive;
		float gravity;
		int speed;
	};
	void initCar();
	void drawCar();
	void moveCarForward();
	void moveCar();
	void attractCarToGround();
}
	