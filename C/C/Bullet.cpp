#include "Bullet.h"

void Bullet::ShootBullet(sf::Vector2f originalPos, sf::Vector2f newDir, float newSpeed) {
    moveDir = newDir;
    moveSpeed = newSpeed;
    pos = originalPos;
    isDisplayed = true;

    if (texture.loadFromFile("../Data/shotsmall.png")) {
        sprite.setTexture(texture);
    }
}

void Bullet::VerifyOffScreen() {
    if(!mustBeRemoved)
        mustBeRemoved = pos.x > 1500;
}

void Bullet::Update(float dt) {
	pos += moveSpeed * moveDir * dt;
    VerifyOffScreen();
}

void Bullet::Display(sf::RenderWindow* window) {
    sprite.setPosition(pos);
    sprite.setScale(sf::Vector2f(3, 3));
    window->draw(sprite);
}