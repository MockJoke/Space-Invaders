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
        }

        void SubzeroController::move()
        {
            switch (enemy_model->getMovementDirection())
            {
            case::Enemy::MovementDirection::DOWN:
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
    }
}
