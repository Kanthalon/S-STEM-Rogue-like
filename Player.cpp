#include "Player.h"

Player::Player()
{
	speed = 3;
	maxjumps = 2;
	jumping = false;
	moveLeft = false;
	moveRight = false;
	pos.x = 100;
	pos.y = 100;
	dim.x = 16;
	dim.y = 32;
}

sf::Vector2f Player::getPos()
{
	return pos;
}

sf::Vector2f Player::getDim()
{
	return dim;
}

void Player::setPos(sf::Vector2f newPos)
{
	pos = newPos;
}

void Player::setDim(sf::Vector2f newDim)
{
	dim = newDim;
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
		if (jumpframes >= 10)
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
	intPos.x = pos.x;
	intPos.y = pos.y;
}

sf::Vector2f* Player::getBlocksOfInterest()
{
	static sf::Vector2f ret[6];
	int index = 0;
	int map = 0xfffffff0;
	intPos.x = intPos.x & map;
	intPos.y = intPos.y & map;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 2; j++) {
			ret[index++] = sf::Vector2f(intPos.x+j*16, intPos.y+i*16);
		}
	}
	return ret;
}