#include "GameManager.h"

GameManager::GameManager() {
    player = new Player(sf::Vector2f(20, 500));

    AddEnemy(new Enemy1(sf::Vector2f(1000, 500)));
}

void GameManager::AddEnemy(Enemy* enemy) {
    enemies.push_back(enemy);
}

void GameManager::AddPlayer(Player* p) {
	player = p;
}

void GameManager::AddBullet(Bullet* b) {
	bullets.push_back(b);
}


void GameManager::ManageInputs() {
    sf::Vector2f input = sf::Vector2f(0, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        input.x = -1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        input.x = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        input.y = 1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        input.y = -1;

    player->ApplyInputs(input);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if(releasedShootKey) AddBullet(player->Shoot());
        releasedShootKey = false;
    }
    else {
        releasedShootKey = true;
    }
}


void GameManager::Update() {
    ManageInputs();
	player->Update();

    auto iteratorB = bullets.end();
    for (int i = bullets.size() - 1; i >= 0; i--) {
        std::advance(iteratorB, -1);
        
        Bullet* bullet = *iteratorB;
        bullet->Update();

        if (bullet->mustBeRemoved) {
            bullets.pop_front();
        }
    }

    auto iteratorE = enemies.begin();
    for (int i = 0; i < enemies.size(); i++) {
        Enemy* enemy = *iteratorE;
        enemy->Update();

        std::advance(iteratorE, 1);
    }
}


void GameManager::Display(sf::RenderWindow* window) {
	player->Display(window);

    auto iteratorB = bullets.begin();
    for (int i = 0; i < bullets.size(); i++) {
        Bullet* bullet = *iteratorB;
        bullet->Display(window);

        std::advance(iteratorB, 1);
    }

    auto iteratorE = enemies.begin();
    for (int i = 0; i < enemies.size(); i++) {
        Enemy* enemy = *iteratorE;
        enemy->Display(window);

        std::advance(iteratorE, 1);
    }
}