#include "Bullet.h"

void Bullet::ShootBullet(sf::Vector2f originalPos, sf::Vector2f newDir, float newSpeed) {
    moveDir = newDir;
    moveSpeed = newSpeed;
    pos = originalPos;
    isDisplayed = true;
}

void Bullet::VerifyOffScreen() {
    mustBeRemoved = pos.x > 1000;
}

void Bullet::Update() {
	pos += moveSpeed * moveDir;
    VerifyOffScreen();
}

void Bullet::Display(sf::RenderWindow* window) {
    if (texture.loadFromFile("shotsmall.png")) {
        sprite.setTexture(texture);
    }
    sprite.setPosition(pos);
    sprite.setScale(sf::Vector2f(3, 3));
    window->draw(sprite);
}