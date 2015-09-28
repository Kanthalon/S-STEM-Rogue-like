#include "Player.h"

Player::Player()
{
	speed = 4;
	maxjumps = 2;
	jumping = false;
	moveLeft = false;
	moveRight = false;
	pos.x = 100;
	pos.y = 100;
}

sf::Vector2f Player::getPos()
{
	return pos;
}

void Player::setPos(sf::Vector2f newPos)
{
	pos = newPos;
}

void Player::jump()
{
	if (jumps) {
		jumpframes = 0;
		jumping = true;
	}
}

void Player::endJump()
{
	if (jumping) {
		jumps--;
		jumping = false;
	}
}

void Player::gravity()
{
	if (pos.y < GROUND) 
	{
		if (velocity.y < MAX_VEL_Y)
		{
			velocity.y += GRAVITY;
		}
	}
}

void Player::move() {
	gravity();
	if (jumping) {
		velocity.y = -5;
		jumpframes++;
		if (jumpframes >= 16)
		{
			endJump();
		}
	}
	if (moveRight) {
		velocity.x += 1;
	} else if (velocity.x > 0) {
		velocity.x -= 0.5;
	}
	if (moveLeft) {
		velocity.x -= 1;
	} else if (velocity.x < 0) {
		velocity.x += 0.5;
	}
	if (velocity.x > speed) {
		velocity.x = speed;
	}
	if (velocity.x < -speed) {
		velocity.x = -speed;
	}
	pos += velocity;
	if (pos.y >= GROUND) {
		pos.y = GROUND;
		velocity.y = 0;
		jumps = maxjumps;
	}
}

