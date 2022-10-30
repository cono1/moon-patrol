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
		float scrollingBack = 0.0f;
		float scrollingMid = 0.0f;
		float scrollingFore = 0.0f;
		Vector2 backgroundA;
		Vector2 backgroundB;
		Vector2 midgroundA;
		Vector2 midgroundB;
		Vector2 foregroundA;
		Vector2 foregroundB;

		InitWindow(1280, 960, "Moon patrol");
		Texture2D background = LoadTexture("Assets/backrgroundLayer.png");
		Texture2D midground = LoadTexture("Assets/midgroundLayer.png");
		Texture2D foreground = LoadTexture("Assets/foregroundLayer.png");
		initMenuButtons(menuSize, mainMenu.menuRect, mainMenu.backRect);
		initCar();
		initObstacle();

		while (!WindowShouldClose() && !mainMenu.exitWindow)
		{
			mainMenu.mousePos = GetMousePosition();
			scrollingBack -= 0.1f;
			scrollingMid -= 0.5f;
			scrollingFore -= 0.2f;

			backgroundA.x = scrollingBack;
			backgroundA.y = 20;
			backgroundB.x = background.width * 2 + scrollingBack;
			backgroundB.y = 20;

			midgroundA.x = scrollingMid;
			midgroundA.y = 10;
			midgroundB.x = midground.width * 2 + scrollingMid;
			midgroundB.y = 10;

			foregroundA.x = scrollingFore;
			foregroundA.y = 500;
			foregroundB.x = foreground.width * 2 + scrollingFore;
			foregroundB.y = 500;

			if (scrollingBack <= -background.width * 2)
			{
				scrollingBack = 0;
			}
			if (scrollingMid <= -midground.width * 2)
			{
				scrollingMid = 0;
			}
			if (scrollingFore <= -foreground.width * 2)
			{
				scrollingFore = 0;
			}

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
			//background
			DrawTextureEx(background, backgroundA, 0.0f, 2.0f, WHITE);
			DrawTextureEx(background, backgroundB, 0.0f,2.0f, WHITE);

			DrawTextureEx(midground, midgroundA, 0.0f, 2.0f, WHITE);
			DrawTextureEx(midground, midgroundB, 0.0f, 2.0f, WHITE);

			DrawTextureEx(foreground, foregroundA, 0.0f, 2.0f, WHITE);
			DrawTextureEx(foreground, foregroundB, 0.0f, 2.0f, WHITE);

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

//background:https://opengameart.org/content/simple-forest-parallax-background