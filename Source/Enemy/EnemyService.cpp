#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/Controllers/SubzeroController.h"
#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/Controllers/ThunderSnakeController.h"

namespace Enemy
{
    EnemyService::EnemyService()
    {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
    }

    EnemyService::~EnemyService() { destroy();}

    void EnemyService::initialize()
    {
        spawn_timer = spawn_interval;
    }

    void EnemyService::update()
    {
        updateSpawnTimer();
        processEnemySpawn();
        
        for (int i = 0; i < enemy_list.size(); i++)
        {
            enemy_list[i]->update();
        }
    }

    void EnemyService::render()
    {
        for (int i = 0; i < enemy_list.size(); i++)
        {
            enemy_list[i]->render();
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
            return new Controller::ZapperController (EnemyType::ZAPPER);

        case::Enemy::EnemyType::THUNDER_SNAKE:
            return new Controller::ThunderSnakeController(Enemy::EnemyType::THUNDER_SNAKE);

        case EnemyType::SUBZERO:
            return new Controller::SubzeroController(EnemyType::SUBZERO);

        // case::Enemy::EnemyType::UFO:
        //     return new UFOController(Enemy::EnemyType::UFO);
        }
    }

    EnemyType EnemyService::getRandomEnemyType()
    {
        int randomType = std::rand() % 3;  //since we only have 3 enemies right now
        return static_cast<Enemy::EnemyType>(randomType);   //cast int to EnemyType enum class
    }
    
    EnemyController* EnemyService::spawnEnemy()
    {
        EnemyController* enemy_controller = createEnemy(getRandomEnemyType());
        
        enemy_controller->initialize();
        enemy_list.push_back(enemy_controller);
        
        return enemy_controller;
    }

    void EnemyService::destroyEnemy(EnemyController* enemy_controller)
    {
        // Erase the enemy_controller object from the enemy_list vector
        // std::remove rearranges the elements in the vector so that all elements 
        // that are equal to enemy_controller are moved to the end of the vector,
        // then it returns an iterator pointing to the start of the removed elements.
        // The erase function then removes those elements from the vector.
        enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), enemy_controller), enemy_list.end());
    
        // Delete the enemy_controller object from memory to free up resources
        delete(enemy_controller);
    }
	
    void EnemyService::destroy()
    {
        for (int i = 0; i < enemy_list.size(); i++)
        {
            delete (enemy_list[i]);
        }
    }
}