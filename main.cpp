#include <raylib.h>
#include "player.h"
#include "obstacles.h"
#include "game.h"

using namespace player;
using namespace obstacles;
using namespace game;

int main()
{
	int version = 01;
	InitWindow(1024, 768, "Moon patrol");
	initCar();
	initObstacle();

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		//auto
		drawCar();
		moveCar();
		moveCarForward();

		//obstaculos
		drawObstacle();
		moveObstacle();

		//mecanicas
		checkCollisions();
		showFinalMessage();
		DrawText(TextFormat("V: %02i", version), GetScreenWidth()-100, GetScreenHeight()-70, 30, WHITE);
		EndDrawing();
	}
	CloseWindow();
}