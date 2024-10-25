#pragma once
#include <SFML/Graphics.hpp>

class Bullet {
public :
	void ShootBullet(sf::Vector2f originalPos, sf::Vector2f newDir, float newSpeed);
	void Update();
	void Display(sf::RenderWindow* window);
	bool mustBeRemoved;
	sf::Vector2f pos;
	double colliderSize;

protected :
	float moveSpeed;
	bool isDisplayed;
	void VerifyOffScreen();
	sf::Vector2f moveDir;
	sf::Texture texture;
	sf::Sprite sprite;
};