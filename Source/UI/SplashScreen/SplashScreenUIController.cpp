#include "../../Header/UI/SplashScreen/SplashScreenUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Global/Config.h"

namespace UI
{
    namespace SplashScreen
    {
        SplashScreenUIController::SplashScreenUIController()
        {
            game_logo_view = new UIElement::AnimatedImageView();
        }

        SplashScreenUIController::~SplashScreenUIController()
        {
            delete (game_logo_view);
        }

        void SplashScreenUIController::initialize()
        {
            initializeGameLogo();
        }

        void SplashScreenUIController::update()
        {
            game_logo_view->update();
        }

        void SplashScreenUIController::render()
        {
            game_logo_view->render();
        }

        void SplashScreenUIController::initializeGameLogo()
        {
            sf::Vector2f position = getLogoPosition();
            game_logo_view->initialize(Global::Config::game_logo_texture_path, logo_width, logo_height, position);
        }

        void SplashScreenUIController::fadeInAnimationCallback()
        {
            game_logo_view->playAnimation(UIElement::AnimationType::FADE_OUT, logo_animation_duration, std::bind(&SplashScreenUIController::fadeOutAnimationCallback, this));
        }

        void SplashScreenUIController::fadeOutAnimationCallback()
        {
            Global::ServiceLocator::getInstance()->getSoundService()->playBackgroundMusic();
            Main::GameService::setGameState(Main::GameState::MAIN_MENU);
        }

        sf::Vector2f SplashScreenUIController::getLogoPosition() const
        {
            sf::RenderWindow* game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            float x_position = (game_window->getSize().x - logo_width) / 2.0f;
            float y_position = (game_window->getSize().y - logo_height) / 2.0f;

            return sf::Vector2f(x_position, y_position);
        }

        void SplashScreenUIController::show()
        {
            game_logo_view->playAnimation(UIElement::AnimationType::FADE_IN, logo_animation_duration, std::bind(&SplashScreenUIController::fadeInAnimationCallback, this));
        }
    }
}