#include <iostream>
#include <raylib.h>
#include "game.h"
#include "player.h"
#include "obstacles.h"

using namespace player;
using namespace obstacles;

extern Rectangle car;
extern Rectangle obstacle;
extern Vehicle vehicle;

namespace game
{
	void gameLoop()
	{
		//init
		int version = 01;
		//menu
		const int menuSize = 3;
		int menuMouseHover = 0;
		int menuOptionSelected = 0;
		bool shouldShowMenu = true;
		bool exitWindow = false;
		Rectangle menuRect[menuSize];
		Rectangle backRect;
		Vector2 mousePos;

		InitWindow(1024, 768, "Moon patrol");
		initMenuButtons(menuSize, menuRect, backRect);
		initCar();
		initObstacle();

		while (!WindowShouldClose() && !exitWindow)
		{
			mousePos = GetMousePosition();
			for (int i = 0; i < menuSize; i++)
			{
				if (CheckCollisionPointRec(mousePos, menuRect[i]))
				{
					menuMouseHover = i;
					break;
				}
				else
				{
					menuMouseHover = -1;
				}
			}

			BeginDrawing();
			ClearBackground(BLACK);

			//menu
			if (shouldShowMenu)
			{
				drawMenu(menuSize, menuRect, menuMouseHover, menuOptionSelected, shouldShowMenu);
			}
			else if (!shouldShowMenu)
			{
				switch (menuOptionSelected)
				{
				case 0: //play
					SetExitKey(0);
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
					DrawText(TextFormat("V: %02i", version), GetScreenWidth() - 100, GetScreenHeight() - 70, 30, WHITE);

					drawBackMenuButton(mousePos, shouldShowMenu, backRect);
					if (IsKeyPressed(KEY_ESCAPE))
					{
						shouldShowMenu = true;
					}
					break;
				case 1: //credits
					showCredits(mousePos, shouldShowMenu, backRect);
					break;
				case 2:
					exitWindow = true;
					shouldShowMenu = false;
					break;
				}
			}
			EndDrawing();
		}
		CloseWindow();
	}

	void initMenuButtons(int menuSize, Rectangle menuRect[], Rectangle& backRect)
	{
		for (int i = 0; i < menuSize; i++)
		{
			menuRect[i].width = 250;
			menuRect[i].height = 70;
			menuRect[i].x = 380;
			menuRect[i].y = 300 + menuRect[i].height * i + 50 * i;
		}
		backRect.x = 10;
		backRect.y = 10;
		backRect.width = 50;
		backRect.height = 25;
	}

	void drawBackMenuButton(Vector2 mousePos, bool& shouldShowMenu, Rectangle backRect)
	{
		DrawRectangle(static_cast<int>(backRect.x), static_cast<int>(backRect.y), static_cast<int>(backRect.width), static_cast<int>(backRect.height), GOLD);
		if (CheckCollisionPointRec(mousePos, backRect))
		{
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				shouldShowMenu = true;
			}
		}
	}

	void drawMenu(int menuSize, Rectangle menuRect[], int menuMouseHover, int& menuOptionSelected, bool& shouldShowMenu)
	{
		SetExitKey(KEY_ESCAPE);
		DrawText("MOON PATROL", 200, 100, 80, RAYWHITE);
		for (int i = 0; i < menuSize; i++)
		{
			DrawRectangle(static_cast<int>(menuRect[i].x), static_cast<int>(menuRect[i].y), static_cast<int>(menuRect[i].width), static_cast<int>(menuRect[i].height), GOLD);
			if (i == 0)
			{
				DrawText("PLAY", static_cast<int>(menuRect[i].x + 55), static_cast<int>(menuRect[i].y + 10), 50, BLACK);
				if (menuMouseHover == 0 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					menuOptionSelected = 0;
					shouldShowMenu = false;
				}
			}
			if (i == 1)
			{
				DrawText("CREDITS", static_cast<int>(menuRect[i].x + 10), static_cast<int>(menuRect[i].y + 10), 50, BLACK);
				if (menuMouseHover == 1 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					menuOptionSelected = 1;
					shouldShowMenu = false;
				}
			}
			if (i == 2)
			{
				DrawText("EXIT", static_cast<int>(menuRect[i].x + 60), static_cast<int>(menuRect[i].y + 10), 50, BLACK);
				if (menuMouseHover == 2 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					menuOptionSelected = 2;
					shouldShowMenu = false;
				}
			}
		}
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
		if (CheckCollisionRecs(car, obstacle))
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