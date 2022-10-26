#include "player.h"
using namespace player;

Car car;

namespace player
{
	void initCar()
	{
		car.pos.x = 10;
		car.pos.y = GetScreenHeight() / 2-50;
		car.size.x = 100;
		car.size.y = 100;
	}

	void drawCar()
	{
		DrawRectangleV(car.pos, car.size, DARKPURPLE);
	}
}