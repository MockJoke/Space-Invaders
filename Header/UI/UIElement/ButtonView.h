#pragma once
#include "../../UI/UIElement/ImageView.h"
#include "../../header/UI/UIElement/TextView.h"
#include <functional>

namespace UI
{
    namespace UIElement
    {
        struct ButtonConfig
        {
            sf::String title;
            sf::String texture_path;
            float button_width = 400.0f;
            float button_height = 150.0f;
            sf::Vector2f position = {0.0f, 0.0f};

            sf::Color image_color = sf::Color::White;
            sf::Color text_color = sf::Color::White;
            sf::Color image_hover_color = sf::Color(128, 128, 128, 255);
            sf::Color text_hover_color = sf::Color(128, 128, 128, 255);
            
            ButtonConfig() = default;
            ButtonConfig(sf::String title, sf::String texture_path) : title(title), texture_path(texture_path) {}
        };
        
        class ButtonView : public ImageView
        {
        private:
            // A function pointer type for the callback function
            using CallbackFunction = std::function<void()>;

            // To store the callback function
            CallbackFunction callback_function = nullptr;

            void printButtonClicked();
            void handleHoverEffect(bool is_hovered);
            
        protected:
            ButtonConfig button_config;
            TextView button_title;
            bool is_hovered = false;

            virtual void handleButtonInteraction();
            virtual bool clickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position);
            virtual bool hoveredOverButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position);

        public:
            ButtonView();
            virtual ~ButtonView();

            virtual void initialize(const ButtonConfig& config);
            virtual void update() override;
            virtual void render() override;

            void registerCallbackFunction(CallbackFunction button_callback);
        };
    }
}
