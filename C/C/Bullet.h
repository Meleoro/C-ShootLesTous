#pragma once
#include <SFML/Graphics.hpp>

class Bullet {
public :
	void Update();
	void Display(sf::RenderWindow* window);

protected :
	float moveSpeed;
	sf::Vector2f moveDir;
	sf::Vector2f pos;
	sf::Texture texture;
	sf::Sprite sprite;
};