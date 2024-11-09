#pragma once
#include <SFML/Graphics.hpp>
#include "../../Global/Config.h"
#include "../../UI/Interface/IUIController.h"
#include "../../UI/UIElement/ImageView.h"
#include "../../UI/UIElement/ButtonView.h"
#include "../../UI/UIElement/TextView.h"

namespace UI
{
    namespace MainMenu
    {
        class MainMenuUIController : public Interface::IUIController
        {
        private:
            const float background_alpha = 85.0f;

            const float play_btn_top_offset = 500.f;
            const float help_btn_top_offset = 700.f;
            const float quit_btn_top_offset = 900.f;

            const float btn_width = 400.f;
            const float btn_height = 140.f;

            UIElement::ImageView* background_image;
            
            UIElement::TextView* menu_title;
            
            UIElement::ButtonView* play_button;
            UIElement::ButtonView* help_button;
            UIElement::ButtonView* quit_button;

            void createBackgroundImage();
            
            void initializeBackgroundImage() const;
            void scaleBackgroundImage();

            void createTitle();
            void initializeTitle() const;

            void createButtons();
            void initializeButtons() const;

            void registerButtonCallback();
            void playButtonCallback();
            void helpButtonCallback();
            void quitButtonCallback();
            
            void destroy() const;
            
        public:
            MainMenuUIController();
            ~MainMenuUIController();
            
            void initialize() override;
            void update() override;
            void render() override;
            void show() override;
        };
    }
}
