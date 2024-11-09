#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/AnimationSystem/AnimationService.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Bullet/BulletController.h"

namespace Enemy
{
    EnemyController::EnemyController(EnemyType type)
    {
        enemy_view = new EnemyView();
        enemy_model = new EnemyModel(type);
    }

    EnemyController::~EnemyController()
    {
        delete (enemy_view);
        delete (enemy_model);
    }

    void EnemyController::initialize()
    {
        enemy_model->initialize();
        enemy_model->setEnemyPosition(getRandomInitialPosition());
        enemy_view->initialize(this);
    }

    void EnemyController::update()
    {
        move();
        updateFireTimer();
        processBulletFire();
        enemy_view->update();
        handleOutOfBounds();
    }

    void EnemyController::render()
    {
        enemy_view->render();
    }

    void EnemyController::updateFireTimer()
    {
        elapsed_fire_duration += Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
    }

    // if elapsed duration is equal to or more than the amount of time,
    // we want to wait until firing then call the fire method
    void EnemyController::processBulletFire()
    {
        if (elapsed_fire_duration >= rate_of_fire)
        {
            fireBullet();
            elapsed_fire_duration = 0.f; // reset elapsed duration back to 0
        }
    }

    sf::Vector2f EnemyController::getRandomInitialPosition() const
    {
        // Calculate the distance between the leftmost and rightmost positions of the enemy
        float x_offset_distance = (std::rand() % static_cast<int>(enemy_model->right_most_position.x - enemy_model->left_most_position.x));
    
        // Calculate the x position by adding the x offset distance to the leftmost position
        float x_position = enemy_model->left_most_position.x + x_offset_distance; 
    
        // The y position remains the same
        float y_position = enemy_model->left_most_position.y;

        // Return the calculated position as a 2D vector
        return sf::Vector2f(x_position, y_position);
    }

    void EnemyController::handleOutOfBounds()
    {
        sf::Vector2f enemyPosition = getEnemyPosition();
        sf::Vector2u windowSize = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

        if (enemyPosition.x < 0 || enemyPosition.x > windowSize.x ||
            enemyPosition.y < 0 || enemyPosition.y > windowSize.y)
        {
            Global::ServiceLocator::getInstance()->getEnemyService()->destroyEnemy(this);
        }
    }

    EnemyType EnemyController::getEnemyType() const
    {
        return enemy_model->getEnemyType();
    }
    
    EnemyState EnemyController::getEnemyState() const
    {
        return enemy_model->getEnemyState();
    }
    
    sf::Vector2f EnemyController::getEnemyPosition() const
    {
        return enemy_model->getEnemyPosition();
    }

    const sf::Sprite& EnemyController::getColliderSprite()
    {
        return enemy_view->getEnemySprite();
    }

    void EnemyController::onCollision(ICollider* other_collider)
    {
        Bullet::BulletController* bullet_controller = dynamic_cast<Bullet::BulletController*>(other_collider);

        if (bullet_controller && bullet_controller->getEntityType() != Entity::EntityType::ENEMY)
        {
            destroy();
            return;
        }

        Player::PlayerController* player_controller = dynamic_cast<Player::PlayerController*>(other_collider);

        if (player_controller)
        {
            destroy();
        }
    }

    void EnemyController::destroy()
    {
        Global::ServiceLocator::getInstance()->getAnimationService()->spawnAnimationSystem(enemy_model->getEnemyPosition(), Animation::AnimationType::EXPLOSION);
        
        Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::EXPLOSION);
        Global::ServiceLocator::getInstance()->getPlayerService()->increaseEnemiesKilled(1);
        Global::ServiceLocator::getInstance()->getEnemyService()->destroyEnemy(this);
    }
}