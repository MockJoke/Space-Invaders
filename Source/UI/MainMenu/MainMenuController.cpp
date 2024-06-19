#include "../../Header/UI/MainMenu/MainMenuController.h"
// #include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/UI/Button.h"

namespace UI
{
    // Nested namespace since everything in MainMenu exists inside UI
    namespace MainMenu
    {
        MainMenuUIController::MainMenuUIController() { game_window = nullptr; }

        void MainMenuUIController::initialize()
        {
            game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
            initializeBackgroundImage();
            initializeTitle();
            initializeButtons();
        }

        void MainMenuUIController::initializeBackgroundImage()
        {
            // Check if a texture is loaded properly
            if (background_texture.loadFromFile(background_texture_path))
            {
                // If it did then set the bg image & scale it
                background_sprite.setTexture(background_texture);
                scaleBackgroundImage();
            }
        }

        void MainMenuUIController::scaleBackgroundImage()
        {
            // Scaling bg image based on the size of the game window 
            background_sprite.setScale(
                static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
                static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
            );
        }

        void MainMenuUIController::initializeTitle()
        {
            title_font.loadFromFile("assets/fonts/ARCADE_I.ttf");
            title_text.setFont(title_font);
            title_text.setString("SPACE INVADERS");
            title_text.setFillColor(sf::Color::White);
            title_text.setCharacterSize(80);
            title_text.setPosition(static_cast<float>(game_window->getSize().x) / 2.f - title_text.getGlobalBounds().width/2.f, 150.f);
        }

        void MainMenuUIController::initializeButtons()
        {
            button_font.loadFromFile("assets/fonts/ARCADE_N.ttf");
            
            play_btn.Create("PLAY", button_font, sf::Color::White, 40);
            instructions_btn.Create("HELP", button_font, sf::Color::White, 40);
            quit_btn.Create("QUIT", button_font, sf::Color::White, 40);
            
            positionButtons();
        }

        void MainMenuUIController::positionButtons()
        {
            play_btn.SetPosition(static_cast<float>(game_window->getSize().x) / 2.f - play_btn.getBounds().x / 2.f, 500.f);
            instructions_btn.SetPosition(static_cast<float>(game_window->getSize().x) / 2.f - instructions_btn.getBounds().x / 2.f, 700.f);
            quit_btn.SetPosition(static_cast<float>(game_window->getSize().x) / 2.f - quit_btn.getBounds().x / 2.f, 900.f);
        }
        
        void MainMenuUIController::update()
        {
        }

        void MainMenuUIController::render()
        {
            game_window->draw(background_sprite);

            game_window->draw(title_text);
            
            play_btn.Render(game_window);
            instructions_btn.Render(game_window);
            quit_btn.Render(game_window);
        }
    }
}