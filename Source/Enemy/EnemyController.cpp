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

    sf::Vector2f EnemyController::getRandomInitialPosition() { return sf::Vector2f(0, 0); }

    void EnemyController::handleOutOfBounds() { }
    
    sf::Vector2f EnemyController::getEnemyPosition() const
    {
        return enemy_model->getEnemyPosition();
    }
}