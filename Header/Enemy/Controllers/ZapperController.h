#pragma once
#include "../EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class ZapperController : public EnemyController
        {
        private:
            float vertical_travel_distance = 90.f;

            void move() override;
            void moveLeft();
            void moveRight();
            void moveDown();

            void fireBullet() override;

            void destroy() override;

        public:
            ZapperController(EnemyType type);
            ~ZapperController();

            void initialize() override;
        };
    }
}