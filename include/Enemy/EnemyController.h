#pragma once
#include <SFML/Graphics.hpp>
#include "EnemyConfig.h"
#include "../Collision/ICollider.h"

namespace Enemy
{
    class EnemyView;
    class EnemyModel;

    enum class EnemyType;
    enum class EnemyState;

    class EnemyController : public Collision::ICollider
    {
    protected:
        float vertical_movement_speed = 30.f;
        float horizontal_movement_speed = 75.0f;
        const float vertical_travel_distance = 60.f;
        
        float rate_of_fire = 3.f;
        float elapsed_fire_duration = 0.f;  // to check how long it has been since we last fired
        
        EnemyView* enemy_view;
        EnemyModel* enemy_model;

        virtual void move() = 0;

        void updateFireTimer();
        void processBulletFire();
        virtual void fireBullet() = 0;

        sf::Vector2f getRandomInitialPosition() const;
        void handleOutOfBounds();

        virtual void destroy();

    public:
        EnemyController(EnemyType type);
        virtual ~EnemyController();

        virtual void initialize();
        void update();
        void render();

        EnemyType getEnemyType() const;
        EnemyState getEnemyState() const;
        sf::Vector2f getEnemyPosition() const;

        virtual void onCollision(ICollider* other_collider) override;
        const sf::Sprite& getColliderSprite() override;
    };
}
