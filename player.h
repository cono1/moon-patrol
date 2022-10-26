#pragma once
#include <raylib.h>

namespace player
{
	struct Car
	{
		Vector2 pos;
		Vector2 size;
	};

	void initCar();
	void drawCar();
}
	