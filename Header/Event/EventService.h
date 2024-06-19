#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace Event
{
    enum class ButtonState
    {
        NONE,
        PRESSED,
        HELD,
        RELEASED,
    };
    
    class EventService
    {
    private:
        sf::Event game_event;   // event var
        sf::RenderWindow* game_window;  // ptr to our game window

        bool isGameWindowOpen() const; 
        bool gameWindowWasClosed() const; // for the condition we already had - the title bar cross
        bool hasQuitGame() const; // for our new 'ESC' condition

        ButtonState left_mouse_button_state;
        ButtonState right_mouse_button_state;
        ButtonState left_arrow_button_state;
        ButtonState right_arrow_button_state;
        ButtonState A_button_state;
        ButtonState D_button_state;

        void updateMouseButtonsState(ButtonState& current_button_state, sf::Mouse::Button mouse_button);
        void updateKeyboardButtonsState(ButtonState& current_button_state, sf::Keyboard::Key keyboard_button);
        
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
        bool pressedAKey() const;
        bool pressedDKey() const;
        bool pressedLeftMouseButton() const;
        bool pressedRightMouseButton() const;
    };
}