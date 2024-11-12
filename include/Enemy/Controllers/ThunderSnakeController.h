#pragma once
#include "../EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class ThunderSnakeController : public EnemyController
        {
        private:
            float horizontal_movement_speed = 150.f;
            // float thunder_snake_horizontal_movement_speed = 150.f;

            void move() override;
            void moveLeft();
            void moveRight();
            void moveDiagonalLeft();
            void moveDiagonalRight();

            MovementDirection getInitialMovementDirection();

            void fireBullet() override;

            void destroy() override;

        public:
            ThunderSnakeController(EnemyType type);
            ~ThunderSnakeController();

            void initialize() override;
        };
    }
}