#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/System.hpp>

class Entity
{
	protected:
		sf::Vector2f pos;
		int width, height;
		bool coll, grav;
		int* sprites;
		int sprite;

	public:
		sf::Vector2f getPos();
		void setPos(sf::Vector2f pos);
};

#endif