#include "../../Header/Enemy/Controllers/UFOController.h"
#include "../../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyModel.h"

namespace Enemy
{
    namespace Controller
    {
        UFOController::UFOController(EnemyType type) : EnemyController(type) { }

        UFOController::~UFOController() { }

        void UFOController::initialize()
        {
            EnemyController::initialize();
        }

        void UFOController::move()
        {
            switch (enemy_model->getMovementDirection())
            {
            case MovementDirection::LEFT:
                moveLeft();
                break;

            case MovementDirection::RIGHT:
                moveRight();
                break;
            }
        }
        
        void UFOController::moveLeft()
        {
            // Get the current position of the enemy
            sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

            // Update the position to move left
            currentPosition.x -= enemy_model->horizontal_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            // Check if the enemy reached the leftmost position
            if (currentPosition.x <= enemy_model->left_most_position.x)
            {
                // Set movement direction to DOWN and update reference position
                enemy_model->setMovementDirection(MovementDirection::DOWN);
                enemy_model->setReferencePosition(currentPosition);
            }
            else
            {
                // Update the enemy position
                enemy_model->setEnemyPosition(currentPosition);
            }
        }
		
        void UFOController::moveRight()
        {
            // Get the current position of the enemy
            sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

            // Update the position to move right
            currentPosition.x += enemy_model->horizontal_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            // Check if the enemy reached the rightmost position
            if (currentPosition.x >= enemy_model->right_most_position.x)
            {
                // Set movement direction to DOWN and update reference position
                enemy_model->setMovementDirection(MovementDirection::DOWN);
                enemy_model->setReferencePosition(currentPosition);
            }
            else
            {
                // Update the enemy position
                enemy_model->setEnemyPosition(currentPosition);
            }
        }

        void UFOController::fireBullet()
        {
        }

        Powerup::PowerupType UFOController::getRandomPowerupType()
        {
            std::srand(static_cast<unsigned int>(std::time(nullptr)));
			
            //We add '1'  to TRIPPLE_LASER below because enum has a 0 index, making the bomb number 2, we need to add 1 to make it 3 
            int random_value = std::rand() % (static_cast<int>(Powerup::PowerupType::TRIPPLE_LASER) + 1);																																																																																
            return static_cast<Powerup::PowerupType>(random_value);
        }
    }
}