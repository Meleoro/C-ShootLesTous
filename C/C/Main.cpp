#include "GameManager.h"
#include "UIManager.h"
#include <SFML/Graphics.hpp>

GameManager* gameManager;
UIManager* uiManager;

int main(int argc, char* argd[]) {
	uiManager = new UIManager();
	gameManager = new GameManager(uiManager);

	sf::RenderWindow window(sf::VideoMode(1500, 1000), "Shoot Em Up");
	sf::Clock clock;
	srand(time(0));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Time time = clock.restart();
		float dt = time.asSeconds();

		window.clear();

		if (!uiManager->gameEnded) {
			gameManager->Update(dt);
			gameManager->Display(&window);
		}

		uiManager->Update(dt);
		uiManager->Display(&window);

		window.display();
	}

	return 0;
}