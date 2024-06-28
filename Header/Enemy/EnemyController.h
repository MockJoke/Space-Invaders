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
        EnemyView* enemy_view;
        EnemyModel* enemy_model;

        virtual void move() = 0;

        sf::Vector2f getRandomInitialPosition();
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
