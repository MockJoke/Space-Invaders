#include "../../Header/Bullet/Controllers/TorpedoeController.h"
#include "../../Header/Bullet/BulletModel.h"

namespace Bullet
{
    namespace Controller
    {
        TorpedoeController::TorpedoeController(BulletType type) : BulletController(type) { }

        TorpedoeController::~TorpedoeController() { }

        void TorpedoeController::initialize(sf::Vector2f position, MovementDirection direction)
        {
            BulletController::initialize(position, direction);
            bullet_model->setMovementSpeed(torpedoe_movement_speed);
        }
    }
}