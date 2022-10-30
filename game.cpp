#include <iostream>
#include <raylib.h>
#include "menu.h"
#include "game.h"
#include "player.h"
#include "obstacles.h"

using namespace menu;
using namespace player;
using namespace obstacles;

extern Rectangle obstacle;
extern Vehicle vehicle;
Menu mainMenu;

namespace game
{
	void gameLoop()
	{
		//init
		int version = 2;	
		InitWindow(1024, 768, "Moon patrol");
		initMenuButtons(menuSize, mainMenu.menuRect, mainMenu.backRect);
		initCar();
		initObstacle();

		while (!WindowShouldClose() && !mainMenu.exitWindow)
		{
			mainMenu.mousePos = GetMousePosition();
			for (int i = 0; i < menuSize; i++)
			{
				if (CheckCollisionPointRec(mainMenu.mousePos, mainMenu.menuRect[i]))
				{
					mainMenu.menuMouseHover = i;
					break;
				}
				else
				{
					mainMenu.menuMouseHover = -1;
				}
			}

			BeginDrawing();
			ClearBackground(BLACK);

			//menu
			if (mainMenu.shouldShowMenu)
			{
				drawMenu(menuSize, mainMenu.menuRect, mainMenu.menuMouseHover, mainMenu.menuOptionSelected, mainMenu.shouldShowMenu);
			}
			else if (!mainMenu.shouldShowMenu)
			{
				switch (mainMenu.menuOptionSelected)
				{
				case 0: //play
					SetExitKey(0);
					//auto
					drawCar();
					moveCar();
					moveCarForward();
					attractCarToGround();

					//obstaculos
					drawObstacle();
					moveObstacle();

					//mecanicas
					checkCollisions();
					showFinalMessage();
					DrawText(TextFormat("V: %02i", version), GetScreenWidth() - 100, GetScreenHeight() - 70, 30, WHITE);

					drawBackMenuButton(mainMenu.mousePos, mainMenu.shouldShowMenu, mainMenu.backRect);
					if (IsKeyPressed(KEY_ESCAPE))
					{
						mainMenu.shouldShowMenu = true;
					}
					break;
				case 1: //credits
					showCredits(mainMenu.mousePos, mainMenu.shouldShowMenu, mainMenu.backRect);
					break;
				case 2: //exit
					mainMenu.exitWindow = true;
					mainMenu.shouldShowMenu = false;
					break;
				}
			}
			EndDrawing();
		}
		CloseWindow();
	}

	void showCredits(Vector2 mousePos, bool& shouldShowMenu, Rectangle backRect)
	{
		SetExitKey(0);
		DrawText("Developed by: Daniela Gonzalez", 120, 300, 50, LIGHTGRAY);
		shouldShowMenu = false;
		drawBackMenuButton(mousePos, shouldShowMenu, backRect);
		if (IsKeyPressed(KEY_ESCAPE))
		{
			shouldShowMenu = true;
		}
	}

	void checkCollisions()
	{
		if (CheckCollisionRecs(vehicle.collidingCarBox, obstacle))
		{
			vehicle.isAlive = false;
		}
	}

	void showFinalMessage()
	{
		if (!vehicle.isAlive)
		{
			DrawText("You loose", 300, 250, 90, RAYWHITE);
		}
	}
}