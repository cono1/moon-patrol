#include "bullet.h"

#include <iostream>
#include "player.h"

using namespace player;

extern Vehicle vehicle;

namespace bullet
{
	Bullet horizontalBullet;

	void initBullet()
    { 
		horizontalBullet.isAlive = true;
		horizontalBullet.collisionBulletBox.width = 10;
		horizontalBullet.collisionBulletBox.height = 5;
		horizontalBullet.collisionBulletBox.x = vehicle.collisionCarBox.x + vehicle.collisionCarBox.width + horizontalBullet.collisionBulletBox.width;
		horizontalBullet.collisionBulletBox.y = vehicle.collisionCarBox.y + 60;
	}

	void drawBullet()
	{
		//if bullet is alive
		if (horizontalBullet.isAlive)
		{
			DrawRectangle(static_cast<int>(horizontalBullet.collisionBulletBox.x), static_cast<int>(horizontalBullet.collisionBulletBox.y), static_cast<int>(horizontalBullet.collisionBulletBox.width), static_cast<int>(horizontalBullet.collisionBulletBox.height), WHITE);		
		}
	}

	void moveBullet()
	{
		horizontalBullet.collisionBulletBox.x += 100 * GetFrameTime();
		if (horizontalBullet.collisionBulletBox.x > GetScreenWidth())
		{
			horizontalBullet.isAlive = false;
		}
	}

}