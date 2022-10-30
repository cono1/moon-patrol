#pragma once

namespace game
{
	void gameLoop();
	void showCredits(Vector2 mousePos, bool& shouldShowMenu, Rectangle backRect);
	void checkCollisions();
	void showFinalMessage();
}