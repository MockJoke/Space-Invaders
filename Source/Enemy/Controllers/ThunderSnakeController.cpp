#include "../../Header/Enemy/Controllers/ThunderSnakeController.h"
#include "../../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyModel.h"

namespace Enemy
{
    namespace Controller
    {
        ThunderSnakeController::ThunderSnakeController(EnemyType type) : EnemyController(type) { }

        ThunderSnakeController::~ThunderSnakeController() { }

        void ThunderSnakeController::initialize()
        {
            EnemyController::initialize();
        }

        void ThunderSnakeController::move()
        {
            switch (enemy_model->getMovementDirection())
            {
            case::Enemy::MovementDirection::LEFT:
                moveLeft();
                break;

            case::Enemy::MovementDirection::RIGHT:
                moveRight();
                break;

            case::Enemy::MovementDirection::LEFT_DOWN:
                moveDiagonalLeft();
                break;

            case::Enemy::MovementDirection::RIGHT_DOWN:
                moveDiagonalRight();
                break;
            }
        }
        
        void ThunderSnakeController::moveLeft()
        {
            // Get the current position of the enemy
            sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

            // Update the position to move left
            currentPosition.x -= enemy_model->horizontal_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            // Check if the enemy reached the leftmost position
            if (currentPosition.x <= enemy_model->left_most_position.x)
            {
                // Set movement direction to EIGHT_DOWN and update reference position
                enemy_model->setMovementDirection(MovementDirection::RIGHT_DOWN);
                enemy_model->setReferencePosition(currentPosition);
            }
            else
            {
                // Update the enemy position
                enemy_model->setEnemyPosition(currentPosition);
            }
        }
		
        void ThunderSnakeController::moveRight()
        {
            // Get the current position of the enemy
            sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

            // Update the position to move right
            currentPosition.x += enemy_model->horizontal_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            // Check if the enemy reached the rightmost position
            if (currentPosition.x >= enemy_model->right_most_position.x)
            {
                // Set movement direction to LEFT_DOWN and update reference position
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
            currentPosition.y += enemy_model->vertical_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
            currentPosition.x -= enemy_model->horizontal_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

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
            currentPosition.y += enemy_model->vertical_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
            currentPosition.x += enemy_model->horizontal_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

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
    }
}