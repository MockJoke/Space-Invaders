#pragma once
#include "../BulletController.h"

namespace Bullet
{
    namespace Controller
    {
        class FrostBulletController : public BulletController
        {
        private:
            const float frost_movement_speed = 400.f;
            
        public:
            FrostBulletController(BulletType bullet_type, Entity::EntityType entity_type);
            ~FrostBulletController();

            void initialize(sf::Vector2f position, MovementDirection direction) override;
        };
    }
}