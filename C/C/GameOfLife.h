#pragma once
#include <SFML/Graphics.hpp>

class GameOfLife {
	public :
		GameOfLife(unsigned int w, unsigned int h);
		~GameOfLife();
		unsigned int getNeighborsCount(unsigned int x, unsigned int y) const;
		bool getValue(int x, int y, bool* currentGrid) const;
		void setValue(int x, int y, bool value, bool* currentGrid) const;
		void doTick();
		bool verifyCell(unsigned int x, unsigned int y);
		sf::Texture generateTexture();
		void drawPixel(unsigned int x, unsigned int y, sf::Color color);

	protected :
		bool* grid;
		bool* saveGrid;
		sf::Texture texture;
		sf::Sprite sprite;
		sf::Image image;
		unsigned int width;
		unsigned int height;
		unsigned int zoomValue = 10;
};