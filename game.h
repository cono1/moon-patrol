#pragma once

namespace game
{
	struct Asset
	{
		float scrollingBack;
		float scrollingMid;
		float scrollingFore;
		Vector2 backgroundA;
		Vector2 backgroundB;
		Vector2 midgroundA;
		Vector2 midgroundB;
		Vector2 foregroundA;
		Vector2 foregroundB;
		Texture2D background;
		Texture2D midground;
		Texture2D foreground;
	};
	void gameLoop();

}