#include <iostream>
#include "Entity.h"
#include "Player.h"
#include "Control.h"

class Player : public Entity
{
	private:
		double damage;
		double health;
		double atkspd, atkdelay;
		double jumpheight;
		int jumps;
		double atkradius, atkarc, atkangle, atkvel, atkduration;
		double speed;
		// Item array
		int items [NUM_ITEMS];
		double dmgmult [NUM_DMG_MULTS];
};