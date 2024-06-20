#pragma once
#include <vector>

namespace Enemy
{
    class EnemyController;
    
    class EnemyService
    {
    private:
        const float spawn_interval = 2.f;
        float spawn_timer;
        
        std::vector<EnemyController*> enemy_list;

        void updateSpawnTimer();
        void processEnemySpawn();
        void destroy();
        
    public:
        EnemyService();
        virtual ~EnemyService();

        void initialize();
        void update();
        void render();

        EnemyController* spawnEnemy();
    };
}