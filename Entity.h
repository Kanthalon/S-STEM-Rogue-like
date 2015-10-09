#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/System.hpp>

using namespace sf;

class Entity
{
	protected:
		Vector2f pos, dim;
		Vector2i intPos, intDim;
		bool coll, grav;
		int* sprites;
		int sprite;

	public:
		Vector2f getPos();
		void setPos(Vector2f pos);
		Vector2f getDim();
};

#endif