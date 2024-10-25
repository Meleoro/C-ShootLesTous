#pragma once
#include "Entity.h"

class Player : public Entity {
public :
	Player(sf::Vector2f startPos);
	void Update() override;
	void Display(sf::RenderWindow* window) override;
	void ApplyInputs(sf::Vector2f input);
	Bullet* Shoot();
};