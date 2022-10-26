#include <raylib.h>
#include "player.h"

using namespace player;

int main()
{
	InitWindow(1024, 768, "Moon patrol");

	while (!WindowShouldClose())
	{
		initCar();
		BeginDrawing();
		ClearBackground(BLACK);
		drawCar();
		EndDrawing();
	}

	CloseWindow();
}