#include "../../include/Powerup/PowerupController.h"
#include "../../include/Powerup/PowerupView.h"
#include "../../include/Powerup/PowerupModel.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Player/PlayerController.h"

namespace Powerup
{
    PowerupController::PowerupController(PowerupType type)
    {
        powerup_view = new PowerupView();
        powerup_model = new PowerupModel(type);
    }

    PowerupController::~PowerupController()
    {
        delete (powerup_view);
        delete (powerup_model);
    }

    void PowerupController::initialize(sf::Vector2f position)
    {
        powerup_model->initialize(position);
        powerup_view->initialize(this);
    }

    void PowerupController::update()
    {
        updatePowerupPosition();
        powerup_view->update();
    }

    void PowerupController::render()
    {
        powerup_view->render();
    }

    void PowerupController::onCollected()
    {
        applyPowerup();
    }

    void PowerupController::updatePowerupPosition()
    {
        sf::Vector2f currentPosition = powerup_model->getPowerupPosition();
        currentPosition.y += powerup_model->getMovementSpeed() * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

        powerup_model->setPowerupPosition(currentPosition);
    }

    void PowerupController::handleOutOfBounds()
    {
        sf::Vector2f powerupPosition = getCollectiblePosition();
        sf::Vector2u windowSize = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

        if (powerupPosition.x < 0 || powerupPosition.x > windowSize.x ||
            powerupPosition.y < 0 || powerupPosition.y > windowSize.y)
        {
            Global::ServiceLocator::getInstance()->getPowerupService()->destroyPowerup(this);
        }
    }

    sf::Vector2f PowerupController::getCollectiblePosition()
    {
        return powerup_model->getPowerupPosition();
    }

    PowerupType PowerupController::getPowerupType() const
    {
        return powerup_model->getPowerupType();
    }

    void PowerupController::onCollision(ICollider* other_collider)
    {
        Player::PlayerController* player_controller = dynamic_cast<Player::PlayerController*>(other_collider);

        if (player_controller)
        {
            onCollected();
            Global::ServiceLocator::getInstance()->getPowerupService()->destroyPowerup(this);
        }
    }
    
    const sf::Sprite& PowerupController::getColliderSprite()
    {
        return powerup_view->getPowerupSprite();
    }
}