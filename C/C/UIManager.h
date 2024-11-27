#pragma once
#include <SFML/Graphics.hpp>

class UIManager {
public :
	void Update(float dt);
	void Display(sf::RenderWindow* window);
	void EndGame();
	void AddScore(int addedScore);
	bool gameEnded = false;

private:
	int score = 0;
	float timer = 0;
	float endTime = 20;
};