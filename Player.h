#ifndef PLAYER_H
#define PLAYER_H

#include "Control.h"
#include "Entity.h"

using namespace sf;

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
		Vector2f velocity;

	public:
		Player();
		Vector2f getPos();
		void setPos(Vector2f pos);
		Vector2f getDim();
		void setDim(Vector2f dim);
		Vector2f getIntPos();
		void setIntPos(Vector2f pos);
		Vector2f getIntDim();
		void setIntDim(Vector2f dim);
		Vector2f* getBlocksOfInterest();
		void collide(Vector2f*);
		void jump();
		void endJump();
		void gravity();
		void move();
		bool moveLeft, moveRight;
};

#endif