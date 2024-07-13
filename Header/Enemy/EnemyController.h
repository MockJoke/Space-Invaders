#pragma once
#include <SFML/Graphics.hpp>
#include "EnemyConfig.h"

namespace Enemy
{
    class EnemyView;
    class EnemyModel;

    enum class EnemyType;
    enum class EnemyState;

    class EnemyController
    {
    protected:
        float rate_of_fire = 3.f;
        float elapsed_fire_duration = 0.f;  // variable to check how long it has been since we last fired
        
        EnemyView* enemy_view;
        EnemyModel* enemy_model;

        virtual void move() = 0;

        void updateFireTimer();
        void processBulletFire();
        virtual void fireBullet() = 0;

        sf::Vector2f getRandomInitialPosition() const;
        void handleOutOfBounds();

    public:
        EnemyController(EnemyType type);
        virtual ~EnemyController();

        virtual void initialize();
        void update();
        void render();

        EnemyType getEnemyType() const;
        EnemyState getEnemyState() const;
        sf::Vector2f getEnemyPosition() const;
    };
}
