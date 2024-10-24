#include "GameManager.h"
#include <SFML/Graphics.hpp>


GameManager* gameManager = new GameManager();


int main(int argc, char* argd[]) {
	Player* player = new Player(sf::Vector2f(20, 500));
	gameManager->AddPlayer(player);

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