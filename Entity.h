#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
	private:
		int x, y;
		int width, height;
		bool coll, grav;
		int* sprites;
		int sprite;
};

#endif