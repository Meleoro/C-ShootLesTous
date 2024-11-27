#include "Background.h"
#include <iostream> 

Background::Background(float speed, std::string textureN, bool rotate90Deg, sf::Vector2f startPos) {
    backgroundSpeed = speed;
    textureName = textureN;

    if (texture.loadFromFile(textureName)) {
        sprite.setTexture(texture);
    }

    rotateBackground = rotate90Deg;

    pos1 = startPos;
    if (rotateBackground) {
        pos2 = startPos + sf::Vector2f(texture.getSize().y * 2, 0);
    }
    else {
        pos2 = startPos + sf::Vector2f(texture.getSize().x * 2, 0);
    }
}

void Background::Update(float dt) {
    pos1 += sf::Vector2f(-1, 0) * backgroundSpeed * dt;
    pos2 += sf::Vector2f(-1, 0) * backgroundSpeed * dt;

    float minX = (float)texture.getSize().x * -2;
    if(rotateBackground)
        minX = (float)texture.getSize().y * -2;

    if (pos1.x < minX) {
        pos1.x += minX * -2;
    } else if (pos2.x < minX) {
        pos2.x += minX * -2;
    }
}

void Background::Display(sf::RenderWindow* window) {
    sprite.setPosition(pos1);

    if(rotateBackground) sprite.setRotation(-90);
    sprite.setScale(sf::Vector2f(2, 2));
    window->draw(sprite);

    sprite.setPosition(pos2);
    if (rotateBackground) sprite.setRotation(-90);
    sprite.setScale(sf::Vector2f(2, 2));
    window->draw(sprite);
}