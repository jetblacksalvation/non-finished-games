#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#define key sf::Keyboard

class player {
private:
	//position and shape
	sf::RectangleShape* player_square;
	float vel_x, vel_y = 0;//velocity variables 

	//misc
	bool IsAlive;
	bool inputs[4] = { 0,0,0,0 };
	enum {
		LEFT,
		RIGHT,
		UP,
		DOWN
	};

public:
	
	player(sf::Vector2f position) {
		IsAlive = true;
		player_square = new sf::RectangleShape({40,40});
		player_square->setFillColor(sf::Color::Red);
		player_square->setPosition(position);
	};
	sf::RectangleShape getShape() {
		return *player_square;
	}
	sf::Vector2f getPos() {
		return player_square->getPosition();
	};
	void setPos(sf::Vector2f new_pos) {
		player_square->setPosition( new_pos);
	}
	bool getIsAlive() { 
		return IsAlive; 
	};
	void getInput() {
		//left
		if (key::isKeyPressed(key::A)) {
			inputs[LEFT] = true;
		}
		else {
			inputs[LEFT] = false;
		}
		//right
		if (key::isKeyPressed(key::D)) {
			inputs[RIGHT] = true;

		}
		else {
			inputs[RIGHT] = false;
		}
		if (key::isKeyPressed(key::W)) {
			inputs[UP] = true;
		}
		else {
			inputs[UP] = false;
		}
		if (key::isKeyPressed(key::S)) {
			inputs[DOWN] = true;
		}
		else {
			inputs[DOWN] = false;
		}
		//end get input


	};
	void handleInput() {
		if (inputs[LEFT] == true) {
			vel_x = -3;
		}
		else if (inputs[RIGHT] == true) {
			vel_x = 3;
		}
		else {
			vel_x = 0;
		}
		if (inputs[UP] == true) {
			vel_y = -3;
		}
		else if (inputs[DOWN] == true) {
			vel_y = 3;
		}
		else {
			vel_y = 0;
		}
		auto temp = player_square->getPosition();
		player_square->setPosition(temp.x + vel_x, temp.y + vel_y);
		return;
	}
};
