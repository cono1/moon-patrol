#pragma once
#include <raylib.h>

namespace player
{
	struct Vehicle
	{
		bool isAlive;
	};
	void initCar();
	void drawCar();
	void moveCarForward();
	void moveCar();
}
	