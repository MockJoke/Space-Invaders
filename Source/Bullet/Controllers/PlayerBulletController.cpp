#include "../../../Header/Bullet/BulletModel.h"
#include "../../../Header/Bullet/Controllers/PlayerBulletController.h"

namespace Bullet
{
    namespace Controller
    {
        PlayerBulletController::PlayerBulletController(BulletType bullet_type, Entity::EntityType entity_type) : BulletController(bullet_type, entity_type) { }

        PlayerBulletController::~PlayerBulletController() { }

        void PlayerBulletController::initialize(sf::Vector2f position, MovementDirection direction)
        {
            BulletController::initialize(position, direction);
            bullet_model->setMovementSpeed(player_bullet_movement_speed);
        }
    }
}