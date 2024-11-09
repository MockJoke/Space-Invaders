#include "../../Header/Powerup/PowerupView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Powerup/PowerupController.h"
#include "../../Header/Powerup/PowerupConfig.h"

namespace Powerup
{
    using namespace Global;

    PowerupView::PowerupView()
    {
        createUIElements();
    }

    PowerupView::~PowerupView() { destroy(); }

    void PowerupView::initialize(PowerupController* controller)
    {
        powerup_controller = controller;
        initializeImage();
    }

    void PowerupView::createUIElements()
    {
        powerup_image = new UI::UIElement::ImageView();
    }

    void PowerupView::initializeImage()
    {
        powerup_image->initialize(getPowerupTexturePath(), powerup_sprite_width, powerup_sprite_height, powerup_controller->getCollectiblePosition());
    }

    void PowerupView::update() const
    {
        powerup_image->setPosition(powerup_controller->getCollectiblePosition());
        powerup_image->update();
    }

    void PowerupView::render() const
    {
        powerup_image->render();
    }

    sf::String PowerupView::getPowerupTexturePath()
    {
        switch (powerup_controller->getPowerupType())
        {
        case PowerupType::SHIELD:
            return Config::shield_texture_path;

        case PowerupType::TRIPLE_LASER:
            return Config::triple_laser_texture_path;

        case PowerupType::RAPID_FIRE:
            return Config::rapid_fire_texture_path;
        }
    }

    const sf::Sprite& PowerupView::getPowerupSprite() const
    { 
        return powerup_image->getSprite();
    }

    void PowerupView::destroy() const
    {
        delete (powerup_image);
    }
}