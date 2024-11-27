#include "Enemy1.h"

Enemy1::Enemy1(sf::Vector2f startPos, std::string spriteName) {
    pos = startPos;
    moveSpeed = 200;
    rotationOffset = -90;


    if (texture.loadFromFile(spriteName)) {
        sprite.setTexture(texture);
    }
}

void Enemy1::Update(float dt) {
    sinTimer += dt * 3.5;
    pos += sf::Vector2f(-1, sin(sinTimer) * 1.25) * moveSpeed * dt;

    VerifyIsOffScreen();
}