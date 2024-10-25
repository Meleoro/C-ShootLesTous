#include "Enemy1.h"

Enemy1::Enemy1(sf::Vector2f startPos) {
    pos = startPos;
    moveSpeed = 0.05f;
}

void Enemy1::Update() {
    pos += sf::Vector2f(-1, 0) * moveSpeed;
}

void Enemy1::Display(sf::RenderWindow* window) {
    if (texture.loadFromFile("boarder.png")) {
        sprite.setTexture(texture);
    }
    sprite.setPosition(pos);
    sprite.setRotation(-90);
    sprite.setScale(sf::Vector2f(3, 3));
    window->draw(sprite);
}


bool Enemy::VerifyCollisions(std::list<Bullet*> bullets) {
    auto iterator = bullets.begin();

    for (int i = 0; i < bullets.size(); i++) {
        Bullet* bullet = *iterator;

        double dist = sqrt(pow(pos.x - bullet->pos.x, 2) + pow(pos.y - bullet->pos.y, 2));
        double collideDist = colliderSize + bullet->colliderSize;

        if (dist < collideDist) {
            return true;
        }

        std::advance(iterator, 1);
    }

    return false;
}