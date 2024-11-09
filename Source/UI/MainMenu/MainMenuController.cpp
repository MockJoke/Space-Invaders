#include "../../../Header/UI/MainMenu/MainMenuController.h"
#include "../../../Header/Main/GameService.h"
#include "../../../Header/Global/ServiceLocator.h"
#include "../../../Header/Graphic/GraphicService.h"

namespace UI
{
    namespace MainMenu
    {
        MainMenuUIController::MainMenuUIController()
        {
            createBackgroundImage();
            createTitle();
            createButtons();
        }

        MainMenuUIController::~MainMenuUIController()
        {
            destroy();
        }
        
        void MainMenuUIController::initialize()
        {
            initializeBackgroundImage();
            initializeTitle();
            initializeButtons();
            registerButtonCallback();
        }

        void MainMenuUIController::createBackgroundImage()
        {
            background_image = new UIElement::ImageView();
        }

        void MainMenuUIController::createTitle()
        {
            menu_title = new UIElement::TextView();
        }
        
        void MainMenuUIController::createButtons()
        {
            play_button = new UIElement::ButtonView();
            help_button = new UIElement::ButtonView();
            quit_button = new UIElement::ButtonView();
        }

        void MainMenuUIController::initializeBackgroundImage() const
        {
            // Check if a texture is loaded properly
            // if (background_texture.loadFromFile(background_texture_path))
            // {
            //     // If it did then set the bg image & scale it
            //     background_sprite.setTexture(background_texture);
            //     scaleBackgroundImage();
            // }

            sf::RenderWindow* game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            background_image->initialize(Global::Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
            background_image->setImageAlpha(background_alpha);
        }

        // void MainMenuUIController::scaleBackgroundImage()
        // {
        //     // Scaling bg image based on the size of the game window 
        //     background_sprite.setScale(
        //         static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
        //         static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
        //     );
        // }

        void MainMenuUIController::initializeTitle() const
        {
            menu_title->initialize("SPACE INVADERS", sf::Vector2f(0, 150.f), UIElement::FontType::ARCADE_I, 80, sf::Color::White);
            menu_title->setTextCentreAligned();
        }

        void MainMenuUIController::initializeButtons() const
        {
            UIElement::ButtonConfig play_button_config("Play", Global::Config::menu_button_texture_path);
            play_button_config.position = {0.0f, play_btn_top_offset};

            play_button->initialize(play_button_config);

            UIElement::ButtonConfig help_button_config("Help", Global::Config::menu_button_texture_path);
            help_button_config.position = {0.0f, help_btn_top_offset};

            help_button->initialize(help_button_config);

            UIElement::ButtonConfig quit_button_config("Quit", Global::Config::menu_button_texture_path);
            quit_button_config.position = {0.0f, quit_btn_top_offset};
            quit_button->initialize(quit_button_config);
            
            play_button->setCentreAligned();
            help_button->setCentreAligned();
            quit_button->setCentreAligned();

            play_button->setImageAlpha(0);
            help_button->setImageAlpha(0);
            quit_button->setImageAlpha(0);
        }

        void MainMenuUIController::registerButtonCallback()
        {
            play_button->registerCallbackFunction(std::bind(&MainMenuUIController::playButtonCallback, this));
            help_button->registerCallbackFunction(std::bind(&MainMenuUIController::helpButtonCallback, this));
            quit_button->registerCallbackFunction(std::bind(&MainMenuUIController::quitButtonCallback, this));
        }

        void MainMenuUIController::playButtonCallback()
        {
            Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
            Main::GameService::setGameState(Main::GameState::GAMEPLAY);
        }

        void MainMenuUIController::helpButtonCallback()
        {
            Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
            Main::GameService::setGameState(Main::GameState::HELP);
        }

        void MainMenuUIController::quitButtonCallback()
        {
            Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->close();
        }
        
        void MainMenuUIController::update()
        {
            background_image->update();
            menu_title->update();
            play_button->update();
            help_button->update();
            quit_button->update();
        }

        void MainMenuUIController::render()
        {
            background_image->render();
            menu_title->render();
            play_button->render();
            help_button->render();
            quit_button->render();
        }

        void MainMenuUIController::show()
        {
            background_image->show();
            play_button->show();
            help_button->show();
            quit_button->show();
        }

        void MainMenuUIController::destroy() const
        {
            delete(play_button);
            delete(help_button);
            delete(quit_button);
            delete(background_image);
        }
    }
}