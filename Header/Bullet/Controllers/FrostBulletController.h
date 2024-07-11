#pragma once
#include "../../Header/Bullet/BulletController.h"

namespace Bullet
{
    namespace Controller
    {
        class FrostBulletController : public BulletController
        {
        private:
            const float frost_movement_speed = 100.f;
            
        public:
            FrostBulletController(BulletType type);
            ~FrostBulletController();

            void initialize(sf::Vector2f position, MovementDirection direction) override;
        };
    }
}