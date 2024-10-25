#include "GameManager.h"
#include <SFML/Graphics.hpp>

GameManager* gameManager;

int main(int argc, char* argd[]) {
	gameManager = new GameManager();

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Shoot Em Up");

	while (window.isOpen())
	{
		window.clear();

		gameManager->Update();
		gameManager->Display(&window);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.display();
	}

	return 0;
}