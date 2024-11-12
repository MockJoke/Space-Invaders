#pragma once
// #include <SFML/Graphics.hpp>
#include "../Global/ServiceLocator.h"

namespace Main
{
    enum class GameState
    {
        BOOT,
        SPLASH_SCREEN,
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
        void initializeVariables();

        void showSplashScreen();
        
        void destroy();

    public:
        GameService();
        ~GameService();

        void ignite();
        void update();
        void render();
        bool isRunning() const;

        static void setGameState(GameState new_state);
        static GameState getGameState();
    };    
}