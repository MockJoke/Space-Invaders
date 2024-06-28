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
        enemy_model->setEnemyPosition(getRandomInitialPosition());
        enemy_view->initialize(this);
    }

    void EnemyController::update()
    {
        move();
        enemy_view->update();
        handleOutOfBounds();
    }

    void EnemyController::render()
    {
        enemy_view->render();
    }

    sf::Vector2f EnemyController::getRandomInitialPosition()
    {
        // Calculate the distance between the leftmost and rightmost positions of the enemy.
        float x_offset_distance = (std::rand() % static_cast<int>(enemy_model->right_most_position.x - enemy_model->left_most_position.x));
    
        // Calculate the x position by adding the x offset distance to the leftmost position.
        float x_position = enemy_model->left_most_position.x + x_offset_distance; 
    
        // The y position remains the same.
        float y_position = enemy_model->left_most_position.y;

        // Return the calculated position as a 2D vector.
        return sf::Vector2f(x_position, y_position);
    }

    void EnemyController::handleOutOfBounds()
    {
        sf::Vector2f enemyPosition = getEnemyPosition();
        sf::Vector2u windowSize = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

        // Destroy the enemy if it goes out of bounds.
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
}