#include "../../../include/Enemy/Controllers/UFOController.h"
#include "../../../include/Global/ServiceLocator.h"
#include "../../../include/Enemy/EnemyModel.h"
#include "../../../include/Bullet/BulletController.h"

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
		
        void UFOController::moveRight()
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

        void UFOController::fireBullet() { }

        Powerup::PowerupType UFOController::getRandomPowerupType()
        {
            std::srand(static_cast<unsigned int>(std::time(nullptr)));
			
            // Add '1' to TRIPLE_LASER below because enum has a 0 index, making the bomb number 2, we need to add 1 to make it 3 
            int random_value = std::rand() % (static_cast<int>(Powerup::PowerupType::TRIPLE_LASER) + 1);																																																																																
            return static_cast<Powerup::PowerupType>(random_value);
        }

        void UFOController::onCollision(ICollider* other_collider)
        {
            EnemyController::onCollision(other_collider);
            Bullet::BulletController* bullet_controller = dynamic_cast<Bullet::BulletController*>(other_collider);

            if (bullet_controller && bullet_controller->getEntityType() != Entity::EntityType::ENEMY)
            {
                Global::ServiceLocator::getInstance()->getPowerupService()->spawnPowerup(getRandomPowerupType(), enemy_model->getEnemyPosition());
            }
        }

        void UFOController::destroy()
        {
            EnemyController::destroy();
        }
    }
}