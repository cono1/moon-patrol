#include <raylib.h>

int main()
{
	InitWindow(600, 400, "Moon patrol");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		EndDrawing();
	}

	CloseWindow();
}