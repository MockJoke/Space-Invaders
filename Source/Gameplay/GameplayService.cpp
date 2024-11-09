#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Gameplay/GameplayController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Gameplay
{
    GameplayService::GameplayService() { gameplay_controller = new GameplayController(); }

    GameplayService::~GameplayService() { delete (gameplay_controller); }

    void GameplayService::initialize() { gameplay_controller->initialize(); }

    void GameplayService::update() { gameplay_controller->update(); }

    void GameplayService::render() { gameplay_controller->render(); }

    void GameplayService::restart()
    {
        Global::ServiceLocator::getInstance()->getPlayerService()->reset();
        Global::ServiceLocator::getInstance()->getEnemyService()->reset();
        Global::ServiceLocator::getInstance()->getBulletService()->reset();
        Global::ServiceLocator::getInstance()->getElementService()->reset();
    }
}
