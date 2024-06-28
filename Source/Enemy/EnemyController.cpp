#include "../../Header/Enemy/EnemyController.h"

#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"

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
        enemy_view->initialize(this);
    }

    void EnemyController::update()
    {
        move();
        enemy_view->update();
    }

    void EnemyController::render()
    {
        enemy_view->render();
    }

    void EnemyController::move()
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

    void EnemyController::moveLeft()
    {
        // Get current pos
        sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
        // Move left by multiplying by speed & delta time
        currentPosition.x -= enemy_model->enemy_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		
        // Check for bounds
        if (currentPosition.x <= enemy_model->left_most_position.x)
        {
            // If reached the left most pos
            // Start moving down
            // Set ref pos for the downwards movement
            enemy_model->setMovementDirection(MovementDirection::DOWN);
            enemy_model->setReferencePosition(currentPosition);
        }
        else
        {
            // If hasn't reached the bounds then keep on moving in the same dir
            enemy_model->setEnemyPosition(currentPosition);
        }
    }
    
    void EnemyController::moveRight()
    {
        sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
        // Move
        currentPosition.x += enemy_model->enemy_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

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

    void EnemyController::moveDown()
    {
        sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
        currentPosition.y += enemy_model->enemy_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		
        // Check if enemy has moved the specified distance downwards
        if (currentPosition.y >= enemy_model->getReferencePosition().y + enemy_model->vertical_travel_distance)
        {
            // Check where to move them based on position
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

    sf::Vector2f EnemyController::getRandomInitialPosition() { return sf::Vector2f(0, 0); }

    void EnemyController::handleOutOfBounds() { }
    
    sf::Vector2f EnemyController::getEnemyPosition() const
    {
        return enemy_model->getEnemyPosition();
    }
}