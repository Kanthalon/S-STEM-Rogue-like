#include <SFML/Graphics.hpp>
#include <iostream>
#include "Control.h"

#define GROUND 200
#define FRAMETIME 0.05

bool canJump = true;
bool jump = false;
bool moveRight = false;
bool moveLeft = false;


void gravity(sf::Vector2f pos, sf::Vector2f &spd);
	
void move(sf::Vector2f &pos, sf::Vector2f &spd);

int main() {
	sf::RenderWindow window(sf::VideoMode(300,300), "Tutorial Title", sf::Style::Default);
	window.setKeyRepeatEnabled(false);
	sf::Vector2f siz, pos, spd;
	siz.x = 10;
	siz.y = 10;
	pos.x = 100;
	pos.y = GROUND;
	spd.x = 0;
	spd.y = 0;
	sf::RectangleShape rect(siz);
	rect.setPosition(pos);
	canJump = true;
	jump = false;

	sf::Clock jumpClock, loopClock;
	sf::Time jumpTime, loopTime;
	rect.setFillColor(sf::Color::Blue);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)){
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Space) {
						if (canJump) {
							jumpClock.restart();
							jump = true;
							canJump = false;
						}
					} else if (event.key.code == sf::Keyboard::Right) {
						moveRight = true;
					} else if (event.key.code == sf::Keyboard::Left) {
						moveLeft = true;
					}
					break;
				case sf::Event::KeyReleased:
					if (event.key.code == sf::Keyboard::Space) {
						if (jump) {
							jump = false;
						}
					} else if (event.key.code == sf::Keyboard::Right) {
						moveRight = false;
					} else if (event.key.code == sf::Keyboard::Left) {
						moveLeft = false;
					}
					break;
			}
		}
		loopTime = loopClock.getElapsedTime();
		if (loopTime.asSeconds() > FRAMETIME) {
			loopClock.restart();
			jumpTime = jumpClock.getElapsedTime();
			if (jumpTime.asSeconds() > 0.2) {
				jump = false;
			}
			gravity(pos, spd);
			move(pos, spd);
			rect.setPosition(pos);
			window.clear();
			window.draw(rect);
			window.display();
		}
	}
}

void gravity(sf::Vector2f pos, sf::Vector2f &spd) {
	if (pos.y < GROUND && !jump) 
	{
		if (spd.y < MAX_VEL_Y)
		{
			spd.y += GRAVITY;
		}
	}
}

void move(sf::Vector2f &pos, sf::Vector2f &spd) {
	if (jump) {
		spd.y = -4;
	}
	if (moveRight) {
		spd.x += 1;
	} else if (spd.x > 0) {
		spd.x -= 0.5;
	}
	if (moveLeft) {
		spd.x -= 1;
	} else if (spd.x < 0) {
		spd.x += 0.5;
	}
	if (spd.x > 4) {
		spd.x = 4;
	}
	if (spd.x < -4) {
		spd.x = -4;
	}
	pos += spd;
	if (pos.y >= GROUND) {
		pos.y = GROUND;
		spd.y = 0;
		canJump = true;
	}
}