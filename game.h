#pragma once

namespace game
{
	void gameLoop();
	void initMenuButtons(int menuSize, Rectangle menuRect[], Rectangle& backRect);
	void drawBackMenuButton(Vector2 mousePos, bool& shouldShowMenu, Rectangle backRect);
	void drawMenu(int menuSize, Rectangle menuRect[], int menuMouseHover, int& menuOptionSelected, bool& shouldShowMenu);
	void showCredits(Vector2 mousePos, bool& shouldShowMenu, Rectangle backRect);
	void checkCollisions();
	void showFinalMessage();
}