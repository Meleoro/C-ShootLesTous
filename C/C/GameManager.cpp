#include "GameManager.h"

GameManager::GameManager() {

}

void GameManager::AddEnemy(Entity* enemy) {

}

void GameManager::AddPlayer(Player* p) {
	player = p;
}

void GameManager::Update() {
	player->Update();
}

void GameManager::Display(sf::RenderWindow* window) {
	player->Display(window);
}