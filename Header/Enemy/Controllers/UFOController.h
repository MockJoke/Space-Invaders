#pragma once
#include "..//EnemyController.h"
#include "../../Powerup/PowerupConfig.h"

namespace Enemy
{
    namespace Controller
    {
        class UFOController : public EnemyController
        {
        private:
            void move() override;
            void moveLeft();
            void moveRight();

            Powerup::PowerupType getRandomPowerupType();

            void fireBullet() override;

            void destroy() override;

        public:
            UFOController(EnemyType type);
            ~UFOController();

            void initialize() override;

            void onCollision(ICollider* other_collider) override;
        };
    }
}