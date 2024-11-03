#pragma once
// #include <SFML/Graphics.hpp>
#include "../Global/ServiceLocator.h"

namespace Main
{
    enum class GameState
    {
        BOOT,
        MAIN_MENU,
        HELP,
        GAMEPLAY,
        CREDITS,
    };
    
    class GameService
    {
    private:
        static GameState current_state;
        
        Global::ServiceLocator* service_locator;
        sf::RenderWindow* game_window;
    
        void initialize();
        void initializeVariables();// Handles game initialization
        void destroy();			// Handles cleanup tasks

    public:
        GameService();			// Constructor for initializing the GameService object
        ~GameService();	        // Destructor for cleaning up resources upon object deletion

        void ignite();			// Initiates the game
        void update();			// Updates the game logic and game state
        void render();			// Renders each frame of the game
        bool isRunning() const;		// Checks if the game is currently running

        static void setGameState(GameState new_state);
        static GameState getGameState();

        void showMainMenu();
    };    
}