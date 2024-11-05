#include "../../Header/Main/GameService.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Main
{
    GameState GameService::current_state = GameState::BOOT;
    
    GameService::GameService()
    {
        service_locator = nullptr;
        // game_window = nullptr;
    }

    GameService::~GameService() { destroy(); }

    void GameService::ignite()
    {
        service_locator = Global::ServiceLocator::getInstance();
        initialize();
    }

    void GameService::initialize()
    {
        service_locator->initialize();
        initializeVariables();
        showSplashScreen();
    }

    void GameService::initializeVariables()
    {
        game_window = service_locator->getGraphicService()->getGameWindow();
    }

    void GameService::update()
    {
        service_locator->getEventService()->processEvents();
        service_locator->update();
    }

    void GameService::render()
    {
        // Clears the game window with the background color provided by the graphic service
        game_window->clear(service_locator->getGraphicService()->getWindowColor());
        service_locator->render();
        game_window->display();
    }

    void GameService::destroy() { }

    void GameService::showSplashScreen()
    {
        setGameState(GameState::SPLASH_SCREEN);
        Global::ServiceLocator::getInstance()->getUIService()->showScreen();
    }

    bool GameService::isRunning() const
    {
        return service_locator->getGraphicService()->isGameWindowOpen();
    }

    void GameService::setGameState(GameState new_state) { current_state = new_state; }

    GameState GameService::getGameState() { return current_state; }
}
