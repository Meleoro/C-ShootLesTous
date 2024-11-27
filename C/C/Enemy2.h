#pragma once
#include "Enemy.h"
#include "Player.h"

class Enemy2 : public Enemy {
public:
	Enemy2(sf::Vector2f startPos, std::string spriteName, Player* player);
	void Update(float dt) override;

protected : 
	Player* player;
};