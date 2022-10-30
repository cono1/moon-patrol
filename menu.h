#pragma once
#include <raylib.h>

namespace menu
{
	const int menuSize = 3;
	struct Menu
	{
		int menuMouseHover = 0;
		int menuOptionSelected = 0;
		bool shouldShowMenu = true;
		bool exitWindow = false;
		Rectangle menuRect[menuSize];
		Rectangle backRect;
		Vector2 mousePos;
	};
	void initMenuButtons(int menuSize, Rectangle menuRect[], Rectangle& backRect);
	void drawBackMenuButton(Vector2 mousePos, bool& shouldShowMenu, Rectangle backRect);
	void drawMenu(int menuSize, Rectangle menuRect[], int menuMouseHover, int& menuOptionSelected, bool& shouldShowMenu);
}