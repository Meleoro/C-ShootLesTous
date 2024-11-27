#include "Entity.h"

void Entity::Display(sf::RenderWindow* window) {
    sprite.setPosition(pos);
    sprite.setRotation(rotationOffset);
    sprite.setScale(sf::Vector2f(3, 3));
    window->draw(sprite);
}