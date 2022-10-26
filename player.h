#pragma once
#include <raylib.h>

namespace player
{
	struct Car
	{
		Vector2 pos;
		Vector2 newPos;
		Vector2 size;
	};

	void initCar();
	void drawCar();
	void moveCarForward();
	void moveCar();
}
	