#ifndef PLAYER_H
#define PLAYER_H

#include "Control.h"
#include "Entity.h"

#define MAX_ATK_SPD
#define MAX_JUMPS 4
#define NUM_DMG_MULTS 4

#define MAX_JUMP_FRAMES

class Player : public Entity
{
	private:
		double damage;
		double health;
		double atkspd, atkdelay;
		double jumpheight;
		int maxjumps;
		double atkradius, atkarc, atkangle, atkvel, atkduration;
		double speed;
		// Item array
		int items [NUM_ITEMS];
		double dmgmult [NUM_DMG_MULTS];

		int jumps;
		bool jumping;
		int jumpframes;
		sf::Vector2f velocity;

	public:
		Player();
		sf::Vector2f getPos();
		void setPos(sf::Vector2f pos);
		void jump();
		void endJump();
		void gravity();
		void move();
		bool moveLeft, moveRight;
};

#endif