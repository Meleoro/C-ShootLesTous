#pragma once
#include <SFML/Graphics.hpp>

class Entity {
public :
	virtual void Update() { };
	void Display(sf::RenderWindow* window);

protected :
	sf::Vector2f pos;
	float moveSpeed = 0.3;
	int health;
	sf::Sprite sprite;
	sf::Texture texture;
};