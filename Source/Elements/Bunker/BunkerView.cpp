#include "../../Header/Elements/Bunker/BunkerView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Elements/Bunker/BunkerController.h"

namespace Element
{
    namespace Bunker
    {
        BunkerView::BunkerView() { createUIElements(); }

        BunkerView::~BunkerView() { destroy(); }

        void BunkerView::initialize(BunkerController* controller)
        {
            bunker_controller = controller;
            initializeImage();
        }

        void BunkerView::createUIElements()
        {
            bunker_image = new UI::UIElement::ImageView();
        }

        void BunkerView::initializeImage() const
        {
            bunker_image->initialize(Global::Config::bunker_texture_path, bunker_sprite_width, bunker_sprite_height, bunker_controller->getBunkerPosition());
        }
        
        void BunkerView::update() const
        {
            bunker_image->update();
        }

        void BunkerView::render() const
        {
            bunker_image->render();
        }

        const sf::Sprite& BunkerView::getBunkerSprite() const
        {
            return bunker_image->getSprite();
        }

        void BunkerView::destroy() const
        {
            delete(bunker_image);
        }
    }
}