#pragma once
#include "Enemy.h"

class Enemy1 : public Enemy {
public:
	Enemy1(sf::Vector2f startPos, std::string spriteName);
	void Update(float dt) override;

protected : 
	float sinTimer = 0;
};