#include "../../../include/Enemy/Controllers/ThunderSnakeController.h"
#include "../../../include/Global/ServiceLocator.h"
#include "../../../include/Enemy/EnemyModel.h"

namespace Enemy
{
    namespace Controller
    {
        ThunderSnakeController::ThunderSnakeController(EnemyType type) : EnemyController(type) { }

        ThunderSnakeController::~ThunderSnakeController() { }

        void ThunderSnakeController::initialize()
        {
            EnemyController::initialize();

            enemy_model->setMovementDirection(getInitialMovementDirection());
            // horizontal_movement_speed = thunder_snake_horizontal_movement_speed;
        }

        MovementDirection ThunderSnakeController::getInitialMovementDirection()
        {
            static MovementDirection initial_direction = MovementDirection::RIGHT;

            switch (initial_direction)
            {
            case MovementDirection::LEFT:
                initial_direction = MovementDirection::RIGHT;
                return initial_direction;

            case MovementDirection::RIGHT:
                initial_direction = MovementDirection::LEFT;
                return initial_direction;
            }
        }

        void ThunderSnakeController::move()
        {
            switch (enemy_model->getMovementDirection())
            {
            case MovementDirection::LEFT:
                moveLeft();
                break;

            case MovementDirection::RIGHT:
                moveRight();
                break;

            case MovementDirection::LEFT_DOWN:
                moveDiagonalLeft();
                break;

            case MovementDirection::RIGHT_DOWN:
                moveDiagonalRight();
                break;
            }
        }
        
        void ThunderSnakeController::moveLeft()
        {
            sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

            currentPosition.x -= horizontal_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            if (currentPosition.x <= enemy_model->left_most_position.x)
            {
                enemy_model->setMovementDirection(MovementDirection::RIGHT_DOWN);
                enemy_model->setReferencePosition(currentPosition);
            }
            else
            {
                enemy_model->setEnemyPosition(currentPosition);
            }
        }
		
        void ThunderSnakeController::moveRight()
        {
            sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

            currentPosition.x += horizontal_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            if (currentPosition.x >= enemy_model->right_most_position.x)
            {
                enemy_model->setMovementDirection(MovementDirection::LEFT_DOWN);
                enemy_model->setReferencePosition(currentPosition);
            }
            else
            {
                enemy_model->setEnemyPosition(currentPosition);
            }
        }

        void ThunderSnakeController::moveDiagonalLeft()
        {
            sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
            currentPosition.y += vertical_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
            currentPosition.x -= horizontal_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            if (currentPosition.x <= enemy_model->left_most_position.x)
            {
                enemy_model->setMovementDirection(MovementDirection::RIGHT);
                enemy_model->setReferencePosition(currentPosition);
            }
            else
            {
                enemy_model->setEnemyPosition(currentPosition);
            }
        }

        void ThunderSnakeController::moveDiagonalRight()
        {
            sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
            currentPosition.y += vertical_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
            currentPosition.x += horizontal_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            if (currentPosition.x >= enemy_model->right_most_position.x)
            {
                enemy_model->setMovementDirection(MovementDirection::LEFT);
                enemy_model->setReferencePosition(currentPosition);
            }
            else
            {
                enemy_model->setEnemyPosition(currentPosition);
            }
        }

        void ThunderSnakeController::fireBullet()
        {
            Global::ServiceLocator::getInstance()->getBulletService()->spawnBullet(Bullet::BulletType::TORPEDO,
                                                                                   enemy_model->getEntityType(),
                                                                                   enemy_model->getEnemyPosition() + enemy_model->barrel_position_offset,
                                                                                   Bullet::MovementDirection::DOWN);
        }

        void ThunderSnakeController::destroy()
        {
            EnemyController::destroy();
        }
    }
}