#include <iostream>

#include "raylib.h"

#include "menu.h"
#include "game.h"
#include "player.h"
#include "obstacles.h"
#include "bullet.h"

using namespace menu;
using namespace player;
using namespace obstacles;
using namespace bullet;

extern Rectangle obstacle;
extern Vehicle vehicle;
Menu mainMenu;

namespace game
{
	//declaraciones
	void initBackground();
	void drawBackground();
	void updateParallax();
	void unloadBackground();
	void showCredits(Vector2 mousePos, bool& shouldShowMenu, Rectangle backRect);
	void checkCollisions();
	void showFinalMessage();

	Asset asset;
	void gameLoop()
	{
		//init
		int version = 2;
		InitWindow(1280, 960, "Moon patrol");
		initMenuButtons(menuSize, mainMenu.menuRect, mainMenu.backRect);
		initBackground();
		initCar();
		initObstacle();
		initBullet();

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
			updateParallax();
			drawBackground();
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

					//balas
					updateBullet();		
					drawBullet();
					moveBullet();

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
		unloadBackground();
		CloseWindow();
	}

	void initBackground()
	{
		asset.scrollingBack = 1;
		asset.scrollingMid = 1;
		asset.scrollingFore = 1;
		asset.background = LoadTexture("Assets/backrgroundLayer.png");
		asset.midground = LoadTexture("Assets/midgroundLayer.png");
		asset.foreground = LoadTexture("Assets/foregroundLayer.png");
	}

	void drawBackground()
	{
		DrawTextureEx(asset.background, asset.backgroundA, 0.0f, 2.0f, WHITE);
		DrawTextureEx(asset.background, asset.backgroundB, 0.0f, 2.0f, WHITE);

		DrawTextureEx(asset.midground, asset.midgroundA, 0.0f, 2.0f, WHITE);
		DrawTextureEx(asset.midground, asset.midgroundB, 0.0f, 2.0f, WHITE);

		DrawTextureEx(asset.foreground, asset.foregroundA, 0.0f, 2.0f, WHITE);
		DrawTextureEx(asset.foreground, asset.foregroundB, 0.0f, 2.0f, WHITE);
	}

	void updateParallax()
	{
		asset.scrollingBack -= 90.f * GetFrameTime();
		asset.scrollingMid -= 50.f * GetFrameTime();
		asset.scrollingFore -= 20.f * GetFrameTime();

		asset.backgroundA.x = asset.scrollingBack;
		asset.backgroundA.y = 20;
		asset.backgroundB.x = asset.background.width * 2 + asset.scrollingBack;
		asset.backgroundB.y = 20;

		asset.midgroundA.x = asset.scrollingMid;
		asset.midgroundA.y = 10;
		asset.midgroundB.x = asset.midground.width * 2 + asset.scrollingMid;
		asset.midgroundB.y = 10;

		asset.foregroundA.x = asset.scrollingFore;
		asset.foregroundA.y = 500;
		asset.foregroundB.x = asset.foreground.width * 2 + asset.scrollingFore;
		asset.foregroundB.y = 500;

		if (asset.scrollingBack <= -asset.background.width * 2)
		{
			asset.scrollingBack = 0;
		}

		if (asset.scrollingMid <= -asset.midground.width * 2)
		{
			asset.scrollingMid = 0;
		}

		if (asset.scrollingFore <= -asset.foreground.width * 2)
		{
			asset.scrollingFore = 0;
		}
	}

	void unloadBackground()
	{
		UnloadTexture(asset.background);
		UnloadTexture(asset.midground);
		UnloadTexture(asset.foreground);
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
		if (CheckCollisionRecs(vehicle.collisionCarBox, obstacle))
		{
			vehicle.isAlive = false;
		}

		if (!vehicle.isAlive && obstacle.x < vehicle.collisionCarBox.x )
		{
			initCar();
			initObstacle();
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