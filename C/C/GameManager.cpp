#include "GameManager.h"

GameManager::GameManager(UIManager* UI) {
    player = new Player(sf::Vector2f(150, 500));
    uiManager = UI;

    AddBackground(new Background(100, "../Data/bg.png", true, sf::Vector2f(0, 1000)));
    AddBackground(new Background(150, "../Data/stars.png", false, sf::Vector2f(0, 0)));
}


#pragma region List Managements

void GameManager::AddEnemy(Enemy* enemy) {
    enemies.push_back(enemy);
}

void GameManager::AddPlayer(Player* p) {
    player = p;
}

void GameManager::AddBullet(Bullet* b) {
    bullets.push_back(b);
}

void GameManager::AddBackground(Background* b) {
    backgrounds.push_back(b);
}

#pragma endregion


void GameManager::ManageInputs() {
    sf::Vector2f input = sf::Vector2f(0, 0);

    // Arrow keys
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        input.x = -1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        input.x = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        input.y = 1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        input.y = -1;

    // We transmit the inputs to the player
    player->ApplyInputs(input);

    // Shoot
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
        if (player->VerifyCanShoot()) 
            AddBullet(player->Shoot());
    }
}


#pragma region Enemy Spawn

void GameManager::ManageEnemySpawn(float dt) {
    currentSpawnTimer += dt;
    if (currentSpawnTimer > currentTimeBetweenSpawn) {

        EnemyType enemyType;
        switch (rand() % 2) {
        case 0:
            enemyType = ENEMY_1;
            break;

        case 1:
            enemyType = ENEMY_2;
            break;
        }

        Enemy* spawnedEnemy = CreateEnemy(enemyType);
        AddEnemy(spawnedEnemy);

        currentSpawnTimer = 0;
        currentTimeBetweenSpawn -= currentTimeBetweenSpawn * 0.01;
        if (currentTimeBetweenSpawn < minTimeBetweenSpawn)
            currentTimeBetweenSpawn = minTimeBetweenSpawn;
    }
}

Enemy* GameManager::CreateEnemy(EnemyType enemyType) {
    switch (enemyType) {
    case ENEMY_1:
        return new Enemy1(sf::Vector2f(1500, rand() % 800 + 100), "../Data/boarder.png");
    case ENEMY_2:
        return new Enemy2(sf::Vector2f(1500, rand() % 800 + 100), "../Data/kamikaze.png", player);
    }
}

#pragma endregion


#pragma region Updates

void GameManager::UpdateBullets(float dt) {
    auto iteratorBullet = bullets.end();
    for (int i = bullets.size() - 1; i >= 0; i--) {
        std::advance(iteratorBullet, -1);

        Bullet* bullet = *iteratorBullet;
        bullet->Update(dt);

        if (bullet->mustBeRemoved) {
            iteratorBullet = bullets.erase(iteratorBullet);
            delete(bullet);
        }
    }
}

void GameManager::UpdateEnemies(float dt) {
    auto iteratorE = enemies.begin();
    for (int i = 0; i < enemies.size(); i++) {
        Enemy* enemy = *iteratorE;
        enemy->Update(dt);
        enemy->VerifyCollisions(bullets);

        if (enemy->mustBeDestroyed) {
            uiManager->AddScore(10);
            iteratorE = enemies.erase(iteratorE);
            delete(enemy);
        }
        else {
            std::advance(iteratorE, 1);
        }
    }
}

void GameManager::UpdateBackgrounds(float dt) {

    auto iteratorBack = backgrounds.begin();
    for (int i = 0; i < backgrounds.size(); i++) {
        Background* background = *iteratorBack;
        background->Update(dt);

        std::advance(iteratorBack, 1);
    }
}

void GameManager::Update(float dt) {
    if (uiManager->gameEnded) return;

    ManageInputs();
    ManageEnemySpawn(dt);

    player->Update(dt);
    player->VerifyCollisions(enemies);
    if (player->mustBeDestroyed) {
        uiManager->EndGame();
    }

    UpdateBullets(dt);
    UpdateEnemies(dt);
    UpdateBackgrounds(dt);
}

#pragma endregion


void GameManager::Display(sf::RenderWindow* window) {
    if (uiManager->gameEnded) return;

    // Backgrounds
    auto iteratorBack = backgrounds.begin();
    for (int i = 0; i < backgrounds.size(); i++) {
        Background* background = *iteratorBack;
        background->Display(window);

        std::advance(iteratorBack, 1);
    }

    // Player
    player->Display(window);

    // Bullets
    auto iteratorB = bullets.begin();
    for (int i = 0; i < bullets.size(); i++) {
        Bullet* bullet = *iteratorB;
        bullet->Display(window);

        std::advance(iteratorB, 1);
    }

    // Enemies
    auto iteratorE = enemies.begin();
    for (int i = 0; i < enemies.size(); i++) {
        Enemy* enemy = *iteratorE;
        enemy->Display(window);

        std::advance(iteratorE, 1);
    }
}