#pragma once
#include <vector>

namespace Enemy
{
    class EnemyController;
    enum class EnemyType;
    
    class EnemyService
    {
    private:
        const float spawn_interval = 2.f;
        float spawn_timer;
        
        std::vector<EnemyController*> enemy_list;
        std::vector<EnemyController*> flagged_enemy_list;

        void updateSpawnTimer();
        void processEnemySpawn();
        
        EnemyType getRandomEnemyType() const;
        EnemyController* createEnemy(EnemyType enemy_type);

        void destroyFlaggedEnemies();
        void destroy() const;
        
    public:
        EnemyService();
        ~EnemyService();

        void initialize();
        void update();
        void render() const;

        void reset();

        EnemyController* spawnEnemy();
        void destroyEnemy(EnemyController* enemy_controller);
    };
}