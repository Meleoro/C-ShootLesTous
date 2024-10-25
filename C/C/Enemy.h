#pragma once
#include "Entity.h"

class Enemy : public Entity {
public:
	bool VerifyCollisions(std::list<Bullet*> bullets);
};