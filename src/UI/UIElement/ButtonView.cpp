#include "../../../include/UI/UIElement/ButtonView.h"
#include "../../../include/Global/ServiceLocator.h"
#include "../../../include/Event/EventService.h"

namespace UI
{
    namespace UIElement
    {
        ButtonView::ButtonView() = default;

        ButtonView::~ButtonView() = default;

        void ButtonView::initialize(const ButtonConfig& config)
        {
            button_config = config;
            
            ImageView::initialize(button_config.texture_path, button_config.button_width, button_config.button_height, button_config.position);
            // ImageView::setColor(button_config.image_color);
            
            button_title.initialize(button_config.title, button_config.position, FontType::ARCADE_N, 40, button_config.text_color);
            button_title.setTextCentreAligned();
        }

        void ButtonView::registerCallbackFunction(CallbackFunction button_callback)
        {
            callback_function = button_callback;
        }

        void ButtonView::update()
        {
            ImageView::update();

            if (ui_state == UIState::VISIBLE)
            {
                handleButtonInteraction();
            }

            button_title.update();
        }

        void ButtonView::render()
        {
            ImageView::render();
            button_title.render();
        }

        void ButtonView::handleButtonInteraction()
        {
            sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

            bool currently_hovered = hoveredOverButton(&image_sprite, mouse_position);

            if (currently_hovered != is_hovered)
            {
                is_hovered = currently_hovered;
                handleHoverEffect(is_hovered);
            }

            // Detect click within bounds
            if (is_hovered && clickedButton(&image_sprite, mouse_position))
            {
                if (callback_function)
                {
                    callback_function();
                }
            }
        }

        bool ButtonView::clickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
        {
            return Global::ServiceLocator::getInstance()->getEventService()->pressedLeftMouseButton() &&
                button_sprite->getGlobalBounds().contains(mouse_position);
        }

        bool ButtonView::hoveredOverButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
        {
            return button_sprite->getGlobalBounds().contains(mouse_position);
        }

        void ButtonView::handleHoverEffect(bool is_hovered)
        {
            if (is_hovered)
            {
                // ImageView::setColor(button_config.image_hover_color);
                button_title.setTextColor(button_config.text_hover_color);
            }
            else
            {
                // ImageView::setColor(button_config.image_hover_color);
                button_title.setTextColor(button_config.text_color);
            }
        }

        void ButtonView::printButtonClicked()
        {
            // printf("Clicked %s\n", button_title.toAnsiString().c_str());
        }
    }
}