#include "Player.h"
#include <iostream>


Player::Player(sf::Vector2f startPos) {
    pos = startPos;
    moveSpeed = 600;
    rotationOffset = 90;
    colliderSize = 25;
    colliderOffset = sf::Vector2f(95, 90);

    if (texture.loadFromFile("../Data/ship2.png")) {
        sprite.setTexture(texture);
    }
}

void Player::ApplyInputs(sf::Vector2f input) {
    currentInput = input;
}

// Manages the delay between the player bullets
void Player::ManageShootTimer(float dt) {
    if (currentShootTimer < shootDelay) {
        currentShootTimer += dt;
    }
}

bool Player::VerifyCanShoot() {
    return currentShootTimer >= shootDelay;
}

// Verify the collision of the player with all the enemies
void Player::VerifyCollisions(std::list<Enemy*> enemies) {
    auto iterator = enemies.begin();

    for (int i = 0; i < enemies.size(); i++) {
        Enemy* enemy = *iterator;

        double dist = sqrt(pow(pos.x - colliderOffset.x - enemy->pos.x, 2) + pow(pos.y + colliderOffset.y - enemy->pos.y, 2));
        double collideDist = colliderSize + enemy->colliderSize;

        // If we collide
        if (dist < collideDist) {
            mustBeDestroyed = true;
            return;
        }

        std::advance(iterator, 1);
    }
}

Bullet* Player::Shoot() {
    Bullet* newBullet = new Bullet();
    newBullet->ShootBullet(pos + sf::Vector2f(0, 25), sf::Vector2f(1, 0), 1000);
    currentShootTimer = 0;
    return newBullet;
}

void Player::Update(float dt) {
    pos += currentInput * moveSpeed * dt;
    ManageShootTimer(dt);
}
