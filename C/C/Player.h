#pragma once
#include "Entity.h"
#include "Enemy.h"

class Player : public Entity {
public :
	Player(sf::Vector2f startPos);
	void Update(float dt) override;
	void ApplyInputs(sf::Vector2f input);
	bool VerifyCanShoot();
	Bullet* Shoot();
	void VerifyCollisions(std::list<Enemy*> enemies);
	bool mustBeDestroyed = false;

protected :
	sf::Vector2f currentInput;
	float currentShootTimer;
	float shootDelay = 0.3f;
	void ManageShootTimer(float dt);
};