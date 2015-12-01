#include "GameState.h"
#include "Player.h"
#include "Bullet.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>



void Player::update()
{
	GameObject::update(); // Update animations



	fireDelay -= sfw::getDeltaTime();
	// example of switching between animations
	if (sfw::getMouseButton(MOUSE_BUTTON_LEFT) && fireDelay < 0)
	{
		int speed1 = rand() % 300 + 300;
		int speed2 = rand() % 300 + 300;
		int speed3 = rand() % 300 + 300;
		int speed4 = rand() % 300 + 300;
		int speed5 = rand() % 300 + 300;
		float spray1 = rand() % 180 - 90; /*for making a spray of shots*/
		float spray2 = rand() % 180 - 90; /*for making a spray of shots*/
		float spray3 = rand() % 180 - 90; /*for making a spray of shots*/
		float spray4 = rand() % 180 - 90; /*for making a spray of shots*/
		float spray5 = rand() % 180 - 90; /*for making a spray of shots*/
		fireDelay = rateOfFire;
		gs()->makeBullet(x, y, spray1, speed1, 2.f); // Now we can use this to draw stuff!
		gs()->makeBullet(x, y, spray2, speed2, 2.f); // Now we can use this to draw stuff!
		gs()->makeBullet(x, y, spray3, speed3, 2.f); // Now we can use this to draw stuff!
		gs()->makeBullet(x, y, spray4, speed4, 2.f); // Now we can use this to draw stuff!
		gs()->makeBullet(x, y, spray5, speed5, 2.f); // Now we can use this to draw stuff!
	}

	if (sfw::getMouseButton(MOUSE_BUTTON_RIGHT) && fireDelay < 0)
	{

		fireDelay = rateOfFire;
		gs()->makeBullet(x, y, 0, 300, 2.f); // Now we can use this to draw stuff!
		gs()->makeBullet(x, y, -90, 300, 2.f); // Now we can use this to draw stuff!
		gs()->makeBullet(x, y, 90, 300, 2.f); // Now we can use this to draw stuff!
		gs()->makeBullet(x, y, -45, 300, 2.f); // Now we can use this to draw stuff!
		gs()->makeBullet(x, y, 45, 300, 2.f); // Now we can use this to draw stuff!
	}


	x = sfw::getMouseX();
	y = sfw::getMouseY();

	/*float sdt = sfw::getDeltaTime() * speed;
	if (sfw::getKey('W')) y += sdt; // Euler integration
	if (sfw::getKey('S')) y -= sdt;
	if (sfw::getKey('A')) x -= sdt;
	if (sfw::getKey('D')) x += sdt;*/
}

void Player::onCollision(GameObject &go, float distance)
{
	switch (go.type)
	{
	case PLAYER:
		break;
	case BULLET:
		if (((Bullet*)(&go))->vely < 0)
			animationName = "Dwead";
			//!isActive;
		// Kill the player
		break;
	case ENEMY:
		break;
	}
}