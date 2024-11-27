#include "Enemy2.h"
#include <algorithm>

Enemy2::Enemy2(sf::Vector2f startPos, std::string spriteName, Player* p) {
    pos = startPos;
    moveSpeed = 150;
    rotationOffset = -90;
    player = p;

    if (texture.loadFromFile(spriteName)) {
        sprite.setTexture(texture);
    }
}

void Enemy2::Update(float dt) {
    sf::Vector2f moveDir = sf::Vector2f(-1, (player->pos.y - pos.y + 80));
    moveDir.y = std::fmax(-50, std::fmin(moveDir.y, 50)) * 0.05;
    pos += moveDir * moveSpeed * dt;

    VerifyIsOffScreen();
}