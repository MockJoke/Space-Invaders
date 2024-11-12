#pragma once
#include "../BulletController.h"

namespace Bullet
{
    namespace Controller
    {
        class PlayerBulletController : public BulletController
        {
        private:
            const float player_bullet_movement_speed = 500.f;
            
        public:
            PlayerBulletController(BulletType bullet_type, Entity::EntityType entity_type);
            ~PlayerBulletController();

            void initialize(sf::Vector2f position, MovementDirection direction) override;
        };
    }
}