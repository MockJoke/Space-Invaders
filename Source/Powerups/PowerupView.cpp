#include "../../header/Powerups/PowerupView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"
#include "../../header/Powerups/PowerupController.h"
#include "../../header/Powerups/PowerupConfig.h"

namespace Powerups
{
    using namespace Global;

    PowerupView::PowerupView() {  }

    PowerupView::~PowerupView() { }

    void PowerupView::initialize(PowerupController* controller)
    {
        powerup_controller = controller;
        game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
        initializeImage(powerup_controller->getPowerupType());
    }

    void PowerupView::initializeImage(PowerupType type)
    {
        switch(type)
        {
        case PowerupType::TRIPPLE_LASER:
            if (powerup_texture.loadFromFile(Config::tripple_laser_texture_path))
            {
                powerup_sprite.setTexture(powerup_texture);
                scaleImage();
            }
            break;
        case PowerupType::SHIELD:
            if (powerup_texture.loadFromFile(Config::shield_texture_path))
            {
                powerup_sprite.setTexture(powerup_texture);
                scaleImage();
            }
            break;
        case PowerupType::RAPID_FIRE:
            if (powerup_texture.loadFromFile(Config::rapid_fire_texture_path))
            {
                powerup_sprite.setTexture(powerup_texture);
                scaleImage();
            }
            break;
        default:
            break;
        }
    }

    void PowerupView::scaleImage()
    {
        powerup_sprite.setScale(
            static_cast<float>(powerup_sprite_width) / powerup_sprite.getTexture()->getSize().x,
            static_cast<float>(powerup_sprite_height) / powerup_sprite.getTexture()->getSize().y
        );
    }

    void PowerupView::update()
    {
        powerup_sprite.setPosition(powerup_controller->getCollectiblePosition());
    }

    void PowerupView::render()
    {
        game_window->draw(powerup_sprite);
    }
}