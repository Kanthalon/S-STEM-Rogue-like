#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/System.hpp>

class Entity
{
	protected:
		sf::Vector2f pos, dim;
		sf::Vector2i intPos, intDim;
		bool coll, grav;
		int* sprites;
		int sprite;

	public:
		sf::Vector2f getPos();
		void setPos(sf::Vector2f pos);
		sf::Vector2f getDim();
};

#endif