#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "list"
#include "Bullet.h"

class Entity {
public :
	virtual void Update() { };
	virtual void Display(sf::RenderWindow* window) { };
	sf::Vector2f pos;
	double colliderSize;

protected :
	float moveSpeed = 0.3;
	int health;
	sf::Sprite sprite;
	sf::Texture texture;
};