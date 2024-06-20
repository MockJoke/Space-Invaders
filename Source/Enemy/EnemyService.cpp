#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{
    EnemyService::EnemyService() { enemy = nullptr; }

    EnemyService::~EnemyService() { destroy();}

    void EnemyService::initialize()
    {
        spawnEnemy();
    }

    void EnemyService::update()
    {
        enemy->update();
    }

    void EnemyService::render()
    {
        enemy->render();
    }

    EnemyController* EnemyService::spawnEnemy()
    {
        //creates & initialize an enemy controller
        enemy = new EnemyController();
        enemy->initialize();

        return enemy;
    }
	
    void EnemyService::destroy()
    {
        //deallocate memory 
        delete(enemy);
    }
}