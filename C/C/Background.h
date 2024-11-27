#pragma once
#include <SFML/Graphics.hpp>

class Background {
public:
	Background(float speed, std::string textureName, bool rotate90Deg, sf::Vector2f startPos);
	void Update(float dt);
	void Display(sf::RenderWindow* window);

protected :
	sf::Vector2f pos1;
	sf::Vector2f pos2;
	float backgroundSpeed;
	bool rotateBackground;
	std::string textureName;
	sf::Texture texture;
	sf::Sprite sprite;
};