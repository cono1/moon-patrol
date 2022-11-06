#pragma once
#include "raylib.h"

namespace bullet
{
	struct Bullet
	{
		bool isAlive;
		int speed;
		Rectangle collisionBulletBox;
	};
	void initBullet();
	void updateBullet();
	void drawBullet();
	void moveBullet();
}