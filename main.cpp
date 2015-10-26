#include <SFML/Graphics.hpp>
#include <iostream>
#include "Control.h"
#include "Player.h"
#include "Game.hpp"

using namespace sf;

bool canJump = true;
bool jump = false;
bool moveRight = false;
bool moveLeft = false;


int main() {
	std::cout << "Starting\n";
	SGE::Game game = SGE::Game();
	game.Run();
	std::cin.get();
}

int oldmain() {
	return 1;
	RenderWindow window(VideoMode(300,300), "Tutorial Title", Style::Default);
	window.setKeyRepeatEnabled(false);
	Vector2f siz, siz2, spd;
	siz2.x = 16;
	siz2.y = 16;
	siz.x = 16;
	siz.y = 32;
	spd.x = 0;
	spd.y = 0;
	Player player;
	RectangleShape rect(player.getDim());
	RectangleShape interest[6];
	for (int i = 0; i < 6; i++) {
		interest[i] = RectangleShape(siz2);
		interest[i].setFillColor(Color::Red);
	}
	Clock loopClock;
	Time loopTime;
	rect.setFillColor(Color::Blue);
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case Event::Closed:
					window.close();
					break;
				case Event::KeyPressed:
					if (event.key.code == Keyboard::Space) {
						player.jump();
					} else if (event.key.code == Keyboard::Right) {
						player.moveRight = true;
					} else if (event.key.code == Keyboard::Left) {
						player.moveLeft = true;
					}
					break;
				case Event::KeyReleased:
					if (event.key.code == Keyboard::Space) {
						player.endJump();
					} else if (event.key.code == Keyboard::Right) {
						player.moveRight = false;
					} else if (event.key.code == Keyboard::Left) {
						player.moveLeft = false;
					}
					break;
			}
		}
		loopTime = loopClock.getElapsedTime();
		if (loopTime.asSeconds() > FRAMETIME) {
			loopClock.restart();
			player.move();
			Vector2f *aoi = player.getBlocksOfInterest();
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
