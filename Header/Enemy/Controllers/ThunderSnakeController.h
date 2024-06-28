#pragma once
#include "../../header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class ThunderSnakeController : public EnemyController
        {
        private:
            float horizontal_movement_speed = 150.f;

            void move() override;
            void moveLeft();
            void moveRight();
            void moveDiagonalLeft();
            void moveDiagonalRight();

        public:
            ThunderSnakeController(EnemyType type);
            ~ThunderSnakeController();

            void initialize() override;
        };
    }
}