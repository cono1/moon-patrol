#include <raylib.h>
#include "player.h"

using namespace player;

int main()
{
	InitWindow(1024, 768, "Moon patrol");

	initCar();
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		drawCar();
		moveCar();
		moveCarForward();
		EndDrawing();
	}

	CloseWindow();
}