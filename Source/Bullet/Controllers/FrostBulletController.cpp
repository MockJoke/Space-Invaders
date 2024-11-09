#include "../../../Header/Bullet/Controllers/FrostBulletController.h"
#include "../../../Header/Bullet/BulletModel.h"

namespace Bullet
{
    namespace Controller
    {
        FrostBulletController::FrostBulletController(BulletType bullet_type, Entity::EntityType entity_type) : BulletController(bullet_type, entity_type) { }

        FrostBulletController::~FrostBulletController() { }

        void FrostBulletController::initialize(sf::Vector2f position, MovementDirection direction)
        {
            BulletController::initialize(position, direction);
            bullet_model->setMovementSpeed(frost_movement_speed);
        }
    }
}