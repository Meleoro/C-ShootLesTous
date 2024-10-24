// C.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define RANDOM(min,max) rand()%(max-min)+min
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "GameOfLife.h"


/*int main()
{
	srand((unsigned)time(NULL));

	GameOfLife* gameOfLife = new GameOfLife(100, 100);


	sf::RenderWindow window(sf::VideoMode(1000, 1000), "GOL");
	sf::Sprite sprite;

	gameOfLife->doTick();
	sf::Texture texture = gameOfLife->generateTexture();;
	sprite.setTexture(texture);

	while (window.isOpen())
	{
		gameOfLife->doTick();
		texture = gameOfLife->generateTexture();
		sprite.setTexture(texture);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}

	return 0;
}*/

