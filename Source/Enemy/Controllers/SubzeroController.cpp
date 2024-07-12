#include "../../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/EnemyModel.h"

namespace Enemy
{
    namespace Controller
    {
        SubzeroController::SubzeroController(EnemyType type) : EnemyController(type) { }

        SubzeroController::~SubzeroController() { }

        void SubzeroController::initialize()
        {
            EnemyController::initialize();
            enemy_model->setMovementDirection(MovementDirection::DOWN);
            rate_of_fire = subzero_rate_of_fire;
        }

        void SubzeroController::move()
        {
            switch (enemy_model->getMovementDirection())
            {
            case MovementDirection::DOWN:
                moveDown();
                break;
            }
        }

        void SubzeroController::moveDown()
        {
            sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
            currentPosition.y += vertical_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            enemy_model->setEnemyPosition(currentPosition);
        }

        void SubzeroController::fireBullet()
        {
            Global::ServiceLocator::getInstance()->getBulletService()->spawnBullet(Bullet::BulletType::FROST_BULLET,
                enemy_model->getEnemyPosition() + enemy_model->barrel_position_offset,
                Bullet::MovementDirection::DOWN);
        }
    }
}
