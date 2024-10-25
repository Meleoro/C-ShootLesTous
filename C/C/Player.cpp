#include "Player.h"
#include <iostream>


Player::Player(sf::Vector2f startPos) {
    pos = startPos;
}

void Player::Update() {
    
}

void Player::Display(sf::RenderWindow* window) {
    if (texture.loadFromFile("ship2.png")) {
        sprite.setTexture(texture);
    }
    sprite.setPosition(pos);
    sprite.setRotation(90);
    sprite.setScale(sf::Vector2f(3, 3));
    window->draw(sprite);
}

void Player::ApplyInputs(sf::Vector2f input) {
    pos += input * moveSpeed;
}

Bullet* Player::Shoot() {
    Bullet* newBullet = new Bullet();
    newBullet->ShootBullet(pos, sf::Vector2f(1, 0), 1);
    return newBullet;
}