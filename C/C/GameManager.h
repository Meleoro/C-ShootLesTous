#pragma once

#include <iostream>
#include "list"
#include "Player.h"
#include "Bullet.h"


class GameManager {
private :
	std::list<Entity*> enemies;
	std::list<Bullet*> bullets;
	Player* player;

public :
	GameManager();
	void AddEnemy(Entity* enemy);
	void AddPlayer(Player* player);
	void AddBullet(Player* bullet);
	void Update();
	void Display(sf::RenderWindow* window);
};