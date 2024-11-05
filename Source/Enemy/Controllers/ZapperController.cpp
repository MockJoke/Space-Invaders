#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyModel.h"

namespace Enemy
{
    namespace Controller
    {
        ZapperController::ZapperController(EnemyType type) : EnemyController(type) { }

        ZapperController::~ZapperController() { }

        void ZapperController::initialize()
        {
            EnemyController::initialize();
        }

        void ZapperController::move()
        {
            switch (enemy_model->getMovementDirection())
            {
            case MovementDirection::LEFT:
                moveLeft();
                break;

            case MovementDirection::RIGHT:
                moveRight();
                break;

            case MovementDirection::DOWN:
                moveDown();
                break;
            }
        }
        
        void ZapperController::moveLeft()
        {
            sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

            currentPosition.x -= horizontal_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            if (currentPosition.x <= enemy_model->left_most_position.x)
            {
                enemy_model->setMovementDirection(MovementDirection::DOWN);
                enemy_model->setReferencePosition(currentPosition);
            }
            else
            {
                enemy_model->setEnemyPosition(currentPosition);
            }
        }
		
        void ZapperController::moveRight()
        {
            sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

            currentPosition.x += horizontal_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            if (currentPosition.x >= enemy_model->right_most_position.x)
            {
                enemy_model->setMovementDirection(MovementDirection::DOWN);
                enemy_model->setReferencePosition(currentPosition);
            }
            else
            {
                enemy_model->setEnemyPosition(currentPosition);
            }
        }

        void ZapperController::moveDown()
        {
            sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

            currentPosition.y += horizontal_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            if (currentPosition.y >= enemy_model->getReferencePosition().y + vertical_travel_distance)
            {
                if (enemy_model->getReferencePosition().x <= enemy_model->left_most_position.x)
                {
                    enemy_model->setMovementDirection(MovementDirection::RIGHT);
                }
                else
                {
                    enemy_model->setMovementDirection(MovementDirection::LEFT);
                }
            }
            else
            {
                enemy_model->setEnemyPosition(currentPosition);
            }
        }

        void ZapperController::fireBullet()
        {
            Global::ServiceLocator::getInstance()->getBulletService()->spawnBullet(Bullet::BulletType::LASER_BULLET,
                                                                                   enemy_model->getEntityType(),
                                                                                   enemy_model->getEnemyPosition() + enemy_model->barrel_position_offset,
                                                                                   Bullet::MovementDirection::DOWN);
        }

        void ZapperController::destroy()
        {
            EnemyController::destroy();
        }
    }
}