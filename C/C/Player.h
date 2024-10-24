#pragma once
#include "Entity.h"

class Player : public Entity {
public :
	Player(sf::Vector2f startPos);
	void Update() override;
	void ApplyInputs();
};