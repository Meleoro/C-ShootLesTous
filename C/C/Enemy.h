#pragma once
#include "Entity.h"

class Enemy : public Entity {
public:
	void VerifyCollisions(std::list<Bullet*> bullets);
	void VerifyIsOffScreen();
	bool mustBeDestroyed = false;
	bool mustGoBackToRight = false;
};