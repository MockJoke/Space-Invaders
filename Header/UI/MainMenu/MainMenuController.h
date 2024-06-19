#pragma once
#include <SFML/Graphics.hpp>
#include "../Button.h"

namespace UI
{
    namespace MainMenu
    {
        class MainMenuUIController
        {
        private:
            const sf::String background_texture_path = "assets/textures/game_bg.png";

            sf::RenderWindow* game_window;

            sf::Texture background_texture;
            sf::Sprite background_sprite;

            sf::Font title_font;
            sf::Text title_text;

            sf::Font button_font;
            Button play_btn;
            Button instructions_btn;
            Button quit_btn;

            // Since this is a single image, we can check if it loaded or not during initialization
            void initializeBackgroundImage();
            void scaleBackgroundImage();

            void initializeTitle();
            
            void initializeButtons();
            void positionButtons();
            
        public:
            MainMenuUIController();

            void initialize();
            void update();
            void render();
        };
    }
}
