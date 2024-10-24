#include "GameOfLife.h"
#include <iostream>

GameOfLife::GameOfLife(unsigned int w, unsigned int h) {
	width = w;
	height = h;
	grid = new bool[w*h];

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			setValue(x, y, false, grid);
		}
	}

	setValue(10, 10, true, grid);
	setValue(11, 10, true, grid);
	setValue(12, 10, true, grid);
}

GameOfLife::~GameOfLife() {
	delete[] grid;
}

unsigned int GameOfLife::getNeighborsCount(unsigned int x, unsigned int y) const {
	int count = 0;

	for (int addedX = -1; addedX <= 1; addedX++) {
		for (int addedY = -1; addedY <= 1; addedY++) {
			if (addedX == addedY && addedX == 0) continue;

			if (getValue(x + addedX, y + addedY, saveGrid)) {
				count += 1;
			}
		}
	}

	return count;
}

bool GameOfLife::getValue(int x, int y, bool* currentGrid) const {

	if (x < 0 || y < 0 || x >= width || y >= height) return false;

	return currentGrid[y * width + x];
}

void GameOfLife::setValue(int x, int y, bool value, bool* currentGrid) const {
	currentGrid[y * width + x] = value;
}

void GameOfLife::doTick() {

	saveGrid = new bool[width * height];
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			if (getValue(x, y, grid)) {
				setValue(x, y, true, saveGrid);
			}
			else {
				setValue(x, y, false, saveGrid);
			}
		}
	}

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			bool result = verifyCell(x, y);
			setValue(x, y, result, grid);
		}
	}
}

bool GameOfLife::verifyCell(unsigned int x, unsigned int y) {
	int neighborCount = getNeighborsCount(x, y);
	bool cellValue = getValue(x, y, saveGrid);

	if (neighborCount < 2)
		cellValue = false;

	else if (neighborCount == 3)
		cellValue = true;

	else if (neighborCount == 4)
		cellValue = false;

	return cellValue;
}

void GameOfLife::drawPixel(unsigned int x, unsigned int y, sf::Color color) {
	for (unsigned int addedX = 0; addedX < zoomValue; addedX++) {
		for (unsigned int addedY = 0; addedY < zoomValue; addedY++) {
			image.setPixel(x * zoomValue + addedX, y * zoomValue + addedY, color);
		}
	}
}

sf::Texture GameOfLife::generateTexture() {
	image.create(width * zoomValue, height * zoomValue, sf::Color::Blue);

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			if (getValue(x, y, grid)) {
				std::cout << getValue(x, y, grid);
				drawPixel(x, y, sf::Color::White);
			}
			else {
				drawPixel(x, y, sf::Color::Black);
			}
		}
	}

	texture.loadFromImage(image);

	return texture;
}