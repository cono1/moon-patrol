#include "bullet.h"

#include <iostream>
#include "player.h"

using namespace player;

extern Vehicle vehicle;

namespace bullet
{
	Bullet verticalBullet;

	void initBullet()
	{
		verticalBullet.isAlive = false;
		verticalBullet.speed = 500;
		verticalBullet.collisionBulletBox.width = 10;
		verticalBullet.collisionBulletBox.height = 5;
		verticalBullet.collisionBulletBox.x = vehicle.collisionCarBox.x + vehicle.collisionCarBox.width / 2;
		verticalBullet.collisionBulletBox.y = vehicle.collisionCarBox.y;
	}

	void updateBullet()
	{
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !verticalBullet.isAlive)
		{
			verticalBullet.isAlive = true;
			verticalBullet.collisionBulletBox.x = vehicle.collisionCarBox.x + vehicle.collisionCarBox.width / 2;
			verticalBullet.collisionBulletBox.y = vehicle.collisionCarBox.y;
		}

		if (verticalBullet.collisionBulletBox.y < 0)
		{
			verticalBullet.isAlive = false;
		}
	}

	void drawBullet()
	{
		if (verticalBullet.isAlive)
		{
			DrawRectangle(static_cast<int>(verticalBullet.collisionBulletBox.x), static_cast<int>(verticalBullet.collisionBulletBox.y), static_cast<int>(verticalBullet.collisionBulletBox.width), static_cast<int>(verticalBullet.collisionBulletBox.height), WHITE);
		}
	}

	void moveBullet()
	{
		if (!verticalBullet.isAlive)
		{
			return;
		}

		verticalBullet.collisionBulletBox.y -= verticalBullet.speed * GetFrameTime();
	}
}