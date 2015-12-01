#include "GameState.h"
#include "Enemy.h"
#include "Bullet.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>


void Enemy::update()
{
	GameObject::update(); // Update animations

	if (fireDelay > 0)
	{

		int speed1 = rand() % 300 + 300;
		float spray1 = rand() % 180 - 90; /*for making a spray of shots*/
		gs()->makeBullet(x, y, spray1, -speed1, 2.f); // Now we can use this to draw stuff!
	}

	x = 400;
	y = 500;
}

void Enemy::onCollision(GameObject &go, float distance)
{
	switch (go.type)
	{
	case ENEMY:
		break;
	case BULLET:
		if (((Bullet*)(&go))->vely > 0)
		{
			isActive = false;
		}
		// Kill the enemy
		break;
	case PLAYER:
		break;
	}
}