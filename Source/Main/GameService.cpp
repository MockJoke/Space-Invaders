#include "../../Header/Main/GameService.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Main
{
    GameState GameService::current_state = GameState::BOOT;
    
    // Constructor: Initializes pointers to null
    GameService::GameService()
    {
        service_locator = nullptr;  // Set service locator to null
        // game_window = nullptr;  // Set game window to null
    }

    // Destructor: Calls the destroy function to clean up resources
    GameService::~GameService()
    {
        destroy();  // Clean up and release resources
    }

    // Prepares the game service for use by obtaining the service locator instance and initializing services
    void GameService::ignite()
    {
        service_locator = Global::ServiceLocator::getInstance();    // Get ServiceLocator
        initialize();   // Initialize services
    }

    // Initialize service locator and other variables
    void GameService::initialize()
    {
        service_locator->initialize();
        initializeVariables();
        showMainMenu();
    }

    void GameService::initializeVariables()
    {
        game_window = service_locator->getGraphicService()->getGameWindow(); // Set game window (it was null before this)
    }

    void GameService::destroy()
    {
        //cleanup resources
    }

    void GameService::update()
    {
        // Process events
        service_locator->getEventService()->processEvents();

        // Update game logic
        service_locator->update();  // Call update on the service locator which then updates all its managed services
    }

    // Clears the window then display it
    void GameService::render()
    {
        // Clears the game window with the background color provided by the graphic service
        game_window->clear(service_locator->getGraphicService()->getWindowColor());
        service_locator->render();  // Render the current frame using the service locator
        game_window->display();     // Display the rendered frame on the game window
    }

    void GameService::showMainMenu()
    {
        setGameState(GameState::MAIN_MENU);
    }

    // Checks if the game is still running by querying the graphic service's window open status
    bool GameService::isRunning() const
    {
        // Returns true if the game window is open, indicating the game is still running
        return service_locator->getGraphicService()->isGameWindowOpen();
    }

    void GameService::setGameState(GameState new_state) { current_state = new_state; }

    GameState GameService::getGameState() { return current_state; }
}
