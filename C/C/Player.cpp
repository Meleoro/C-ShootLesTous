#include "Player.h"
#include <iostream>


Player::Player(sf::Vector2f startPos) {
    pos = startPos;
}

void Player::Update() {
    ApplyInputs();
}

void Entity::Display(sf::RenderWindow* window) {
    if (texture.loadFromFile("ship2.png")) {
        sprite.setTexture(texture);
    }
    sprite.setPosition(pos);
    sprite.setRotation(90);
    sprite.setScale(sf::Vector2f(3, 3));
    window->draw(sprite);
}

void Player::ApplyInputs() {
    sf::Vector2f input = sf::Vector2f(0, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        input.x = -1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        input.x = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        input.y = 1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        input.y = -1;

    pos += input * moveSpeed;
}