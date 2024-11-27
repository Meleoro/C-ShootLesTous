#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "list"
#include "Bullet.h"

class Entity {
public :
	virtual void Update(float dt) { };
	void Display(sf::RenderWindow* window);
	sf::Vector2f pos;
	double colliderSize = 45;     // 45 car mes sprites font en moyenne 30 pixels de large / hauteur, je les affiche avec une scale multipliée fois 3, donc le rayon de leur collider est 45

protected :
	sf::Vector2f colliderOffset = sf::Vector2f(45, 45);     // Meme logique que pour le ColliderSize ici
	float moveSpeed = 100;
	float rotationOffset;
	int health;
	sf::Sprite sprite;
	sf::Texture texture;
};