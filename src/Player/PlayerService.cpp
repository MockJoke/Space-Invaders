#include "../../include/Player/PlayerService.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Player/PlayerController.h"

namespace Player
{
    PlayerService::PlayerService()
    {
        player_controller = new PlayerController();
    }

    PlayerService::~PlayerService()
    {
        Global::ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<Collision::ICollider*>(player_controller));
        delete(player_controller);
    }

    void PlayerService::initialize()
    {
        player_controller->initialize();
        Global::ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<Collision::ICollider*>(player_controller));
    }

    void PlayerService::update()
    {
        player_controller->update();
    }

    void PlayerService::render()
    {
        player_controller->render();
    }

    void PlayerService::reset()
    {
        player_controller->reset();
    }
    
    void PlayerService::increaseEnemiesKilled(int val) const
    {
        player_controller->increaseEnemiesKilled(val);
    }
	
    void PlayerService::enableShield() const
    {
        player_controller->enableShield();
    }

    void PlayerService::enableRapidFire() const
    {
        player_controller->enableRapidFire();
    }

    void PlayerService::enableTripleLaser() const
    {
        player_controller->enableTripleLaser();
    }
}