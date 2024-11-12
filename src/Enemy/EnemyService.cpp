#include "../../include/Enemy/EnemyService.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Enemy/EnemyController.h"
#include "../../include/Enemy/Controllers/SubzeroController.h"
#include "../../include/Enemy/Controllers/ZapperController.h"
#include "../../include/Enemy/Controllers/ThunderSnakeController.h"
#include "../../include/Enemy/Controllers/UFOController.h"

namespace Enemy
{
    EnemyService::EnemyService()
    {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
    }

    EnemyService::~EnemyService() { destroy(); }

    void EnemyService::initialize()
    {
        spawn_timer = spawn_interval;
    }

    void EnemyService::update()
    {
        updateSpawnTimer();
        processEnemySpawn();
        
        for (EnemyController* enemy : enemy_list)
        {
            enemy->update();
        }

        destroyFlaggedEnemies();
    }

    void EnemyService::render() const
    {
        for (EnemyController* enemy : enemy_list)
        {
            enemy->render();
        }
    }

    void EnemyService::updateSpawnTimer()
    {
        spawn_timer += Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
    }

    void EnemyService::processEnemySpawn()
    {
        if (spawn_timer >= spawn_interval)
        {
            spawnEnemy(); 
            spawn_timer = 0.0f;
        }
    }

    EnemyController* EnemyService::createEnemy(EnemyType enemy_type)
    {
        switch (enemy_type)
        {
        case EnemyType::ZAPPER:
            return new Controller::ZapperController(EnemyType::ZAPPER);

        case EnemyType::THUNDER_SNAKE:
            return new Controller::ThunderSnakeController(EnemyType::THUNDER_SNAKE);

        case EnemyType::SUBZERO:
            return new Controller::SubzeroController(EnemyType::SUBZERO);

        case EnemyType::UFO:
            return new Controller::UFOController(EnemyType::UFO);
        }
    }

    EnemyType EnemyService::getRandomEnemyType() const
    {
        int randomType = std::rand() % 4;
        return static_cast<EnemyType>(randomType);
    }
    
    EnemyController* EnemyService::spawnEnemy()
    {
        EnemyController* enemy_controller = createEnemy(getRandomEnemyType());
        
        enemy_controller->initialize();
        Global::ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<Collision::ICollider*>(enemy_controller));
        
        enemy_list.push_back(enemy_controller);
        
        return enemy_controller;
    }

    void EnemyService::reset()
    {
        destroy();
        spawn_timer = 0.0f;
    }

    void EnemyService::destroyFlaggedEnemies()
    {
        for (int i = 0; i < flagged_enemy_list.size(); i++)
        {
            Global::ServiceLocator::getInstance()->getCollisionService()->removeCollider(flagged_enemy_list[i]);
            delete (flagged_enemy_list[i]);
        }
        
        flagged_enemy_list.clear();
    }

    void EnemyService::destroyEnemy(EnemyController* enemy_controller)
    {
        enemy_controller->disableCollision();
        flagged_enemy_list.push_back(enemy_controller);
        enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), enemy_controller), enemy_list.end());
    }
	
    void EnemyService::destroy() const
    {
        for (auto enemy : enemy_list)
        {
            delete (enemy);
        }
    }
}