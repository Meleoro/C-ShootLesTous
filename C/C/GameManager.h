#pragma once

#include <iostream>
#include <list>
#include "Player.h"
#include "Enemy.h"
#include "Enemy1.h"
#include "Bullet.h"
#include <iterator>


class GameManager {
private :
	std::list<Enemy*> enemies;
	std::list<Bullet*> bullets;
	bool releasedShootKey = false;
	Player* player;

public :
	GameManager();
	void AddEnemy(Enemy* enemy);
	void AddPlayer(Player* player);
	void AddBullet(Bullet* bullet);
	void ManageInputs();
	void Update();
	void Display(sf::RenderWindow* window);
};