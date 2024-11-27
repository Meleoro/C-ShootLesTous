#include "UIManager.h"
#include <sstream>

void UIManager::Update(float dt) {
	if(!gameEnded)
		timer += dt;
}

std::string ToString(int integer)
{
	std::ostringstream os;
	os << integer;
	return os.str();
}

void UIManager::Display(sf::RenderWindow* window) {
	sf::Font font;
	font.loadFromFile("../Data/font.ttf");

	if (!gameEnded) {
		sf::Text scoreText("SCORE : " + ToString(score), font);
		scoreText.setCharacterSize(30);
		scoreText.setStyle(sf::Text::Bold);
		scoreText.setFillColor(sf::Color::White);

		window->draw(scoreText);
	}
	else {
		std::string gameOverString = "YOU LOST";
		if (timer > endTime) {
			gameOverString = "YOU WON";
		}

		sf::Text gameOver (gameOverString, font);

		gameOver.setCharacterSize(60);
		gameOver.setPosition(500, 350);
		gameOver.setStyle(sf::Text::Bold);
		gameOver.setFillColor(sf::Color::White);

		window->draw(gameOver);

		sf::Text scoreText("YOUR FINAL SCORE IS : " + ToString(score), font);
		scoreText.setCharacterSize(30);
		scoreText.setStyle(sf::Text::Bold);
		scoreText.setFillColor(sf::Color::White);
		scoreText.setPosition(500, 500);

		window->draw(scoreText);

		sf::Text timeText("YOUR TIME IS : " + ToString((int)timer) + " SECONDS", font);
		timeText.setCharacterSize(30);
		timeText.setStyle(sf::Text::Bold);
		timeText.setFillColor(sf::Color::White);
		timeText.setPosition(500, 600);

		window->draw(timeText);
	}
}

void UIManager::EndGame() {
	gameEnded = true;
}

void UIManager::AddScore(int addedScore) {
	score += addedScore;
}