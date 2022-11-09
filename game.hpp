#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp"
//this class initializes all game variables 

class Game :private player {

private:
	sf::RenderWindow* window;
	sf::Clock clock;
	sf::Event event;
public:
	Game() : player({ 400,400 }) {
		window = new sf::RenderWindow({ 800,800 }, "Game Window");
		window->setFramerateLimit(60);

	};
	//this function is the main loop 
	void run_game() {
		while (window->isOpen() == true && getIsAlive()!= false) {
			while (window->pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					puts("bye ");
					exit(0);
				}
				getInput();
				//handle events here
			}
			handleInput();
			window->clear(sf::Color::Black);
			window->draw(getShape());
			//draw and do math here 
			window->display();
			
		}

	};
};