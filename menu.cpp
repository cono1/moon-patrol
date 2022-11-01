#include "menu.h"

namespace menu
{
	void initMenuButtons(int menuSize, Rectangle menuRect[], Rectangle& backRect)
	{
		for (int i = 0; i < menuSize; i++)
		{
			menuRect[i].width = 250;
			menuRect[i].height = 70;
			menuRect[i].x = static_cast<float>(GetScreenWidth() - 800);
			menuRect[i].y = 300 + menuRect[i].height * i + 50 * i;
		}
		backRect.x = 10;
		backRect.y = 10;
		backRect.width = 50;
		backRect.height = 25;
	}

	void drawBackMenuButton(Vector2 mousePos, bool& shouldShowMenu, Rectangle backRect)
	{
		DrawRectangle(static_cast<int>(backRect.x), static_cast<int>(backRect.y), static_cast<int>(backRect.width), static_cast<int>(backRect.height), WHITE);
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
		DrawText("MOON PATROL", 300, 100, 100, RAYWHITE);
		for (int i = 0; i < menuSize; i++)
		{
			DrawRectangle(static_cast<int>(menuRect[i].x), static_cast<int>(menuRect[i].y), static_cast<int>(menuRect[i].width), static_cast<int>(menuRect[i].height), WHITE);
			if (i == 0)
			{
				DrawText("PLAY", static_cast<int>(menuRect[i].x + 55), static_cast<int>(menuRect[i].y + 10), 50, BLACK);
				if (menuMouseHover == 0 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					menuOptionSelected = 0;
					shouldShowMenu = false;
				}
			}
			else if (i == 1)
			{
				DrawText("CREDITS", static_cast<int>(menuRect[i].x + 10), static_cast<int>(menuRect[i].y + 10), 50, BLACK);
				if (menuMouseHover == 1 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					menuOptionSelected = 1;
					shouldShowMenu = false;
				}
			}
			else if (i == 2)
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
}