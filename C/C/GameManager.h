#pragma once

#include <iostream>
#include <list>
#include "Player.h"
#include "Enemy.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Bullet.h"
#include "Background.h"
#include <iterator>
#include "UIManager.h"


class GameManager {
private :
	std::list<Enemy*> enemies;
	std::list<Bullet*> bullets;
	std::list<Background*> backgrounds;
	Player* player;
	float currentSpawnTimer;
	float currentTimeBetweenSpawn = 1;
	float minTimeBetweenSpawn = 0.04;
	UIManager* uiManager;
	void UpdateBullets(float dt);
	void UpdateEnemies(float dt);
	void UpdateBackgrounds(float dt);

public :
	GameManager(UIManager* UIManager);
	typedef enum { ENEMY_1, ENEMY_2 } EnemyType;
	void AddEnemy(Enemy* enemy);
	void AddPlayer(Player* player);
	void AddBullet(Bullet* bullet);
	void AddBackground(Background* background);
	void ManageInputs();
	void ManageEnemySpawn(float dt);
	Enemy* CreateEnemy(EnemyType enemyType);
	void Update(float dt);
	void Display(sf::RenderWindow* window);
};