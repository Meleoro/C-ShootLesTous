#pragma once
#include "Enemy.h"

class Enemy1 : public Enemy {
public:
	Enemy1(sf::Vector2f startPos);
	void Update() override;
	void Display(sf::RenderWindow* window) override;
};