#include <SFML/Graphics.hpp>
#include <iostream>
#include "Control.h"
#include "Player.h"

bool canJump = true;
bool jump = false;
bool moveRight = false;
bool moveLeft = false;


int main() {
	sf::RenderWindow window(sf::VideoMode(300,300), "Tutorial Title", sf::Style::Default);
	window.setKeyRepeatEnabled(false);
	sf::Vector2f siz, siz2, spd;
	siz2.x = 16;
	siz2.y = 16;
	siz.x = 16;
	siz.y = 32;
	spd.x = 0;
	spd.y = 0;
	Player player;
	sf::RectangleShape rect(player.getDim());
	sf::RectangleShape interest[6];
	for (int i = 0; i < 6; i++) {
		interest[i] = sf::RectangleShape(siz2);
		interest[i].setFillColor(sf::Color::Red);
	}
	sf::Clock loopClock;
	sf::Time loopTime;
	rect.setFillColor(sf::Color::Blue);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Space) {
						player.jump();
					} else if (event.key.code == sf::Keyboard::Right) {
						player.moveRight = true;
					} else if (event.key.code == sf::Keyboard::Left) {
						player.moveLeft = true;
					}
					break;
				case sf::Event::KeyReleased:
					if (event.key.code == sf::Keyboard::Space) {
						player.endJump();
					} else if (event.key.code == sf::Keyboard::Right) {
						player.moveRight = false;
					} else if (event.key.code == sf::Keyboard::Left) {
						player.moveLeft = false;
					}
					break;
			}
		}
		loopTime = loopClock.getElapsedTime();
		if (loopTime.asSeconds() > FRAMETIME) {
			loopClock.restart();
			player.move();
			sf::Vector2f *aoi = player.getBlocksOfInterest();
			for (int i = 0; i < 6; i++) {
				interest[i].setPosition(aoi[i]);
			}
			rect.setPosition(player.getPos());
			window.clear();
			for (int i = 0; i < 6; i++) {
				window.draw(interest[i]);
			}
			window.draw(rect);
			window.display();
		}
	}
}
