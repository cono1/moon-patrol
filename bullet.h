#pragma once
#include "raylib.h"

namespace bullet
{
	struct Bullet
	{
		bool isAlive;
		Rectangle collisionBulletBox;
	};
	void initBullet();
	void drawBullet();
	void moveBullet();
}