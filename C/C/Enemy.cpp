#include "Enemy.h"

// Verify collision with all the player's bullets
void Enemy::VerifyCollisions(std::list<Bullet*> bullets) {
    auto iterator = bullets.begin();

    for (int i = 0; i < bullets.size(); i++) {
        Bullet* bullet = *iterator;

        double dist = sqrt(pow(pos.x + colliderOffset.x - bullet->pos.x, 2) + pow(pos.y - colliderOffset.y - bullet->pos.y, 2));
        double collideDist = colliderSize + bullet->colliderSize;

        if (dist < collideDist) {
            mustBeDestroyed = true;
            bullet->mustBeRemoved = true;
            return;
        }

        std::advance(iterator, 1);
    }
}

void Enemy::VerifyIsOffScreen() {
    if (pos.x < -60) {
        pos.x += 1560;
    }
}