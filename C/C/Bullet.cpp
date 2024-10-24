#include "Bullet.h"

void Bullet::Update() {
	pos += moveSpeed * moveDir;
}

void Bullet::Display(sf::RenderWindow* window) {
    if (texture.loadFromFile("shotsmall.png")) {
        sprite.setTexture(texture);
    }
    sprite.setPosition(pos);
    sprite.setScale(sf::Vector2f(3, 3));
    window->draw(sprite);
}