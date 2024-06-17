#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace Event
{
    class EventService
    {
    private:
        sf::Event game_event;   // event var
        sf::RenderWindow* game_window;  // ptr to our game window

        bool isGameWindowOpen() const; 
        bool gameWindowWasClosed() const; // for the condition we already had - the title bar cross
        bool hasQuitGame() const; // for our new 'ESC' condition

    public:
        EventService();
        ~EventService();

        void initialize();
        void update();
        void processEvents();   // while window is open we will check for events
        bool pressedEscapeKey() const;
        bool isKeyboardEvent() const;
        bool pressedLeftKey() const;
        bool pressedRightKey() const;
    };
}