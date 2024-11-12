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
        sf::Event game_event;
        sf::RenderWindow* game_window;

        ButtonState left_mouse_button_state;
        ButtonState right_mouse_button_state;
        ButtonState left_arrow_button_state;
        ButtonState right_arrow_button_state;
        ButtonState A_button_state;
        ButtonState D_button_state;

        bool isGameWindowOpen() const; 
        bool gameWindowWasClosed() const;
        bool hasQuitGame() const;

        void updateMouseButtonsState(ButtonState& current_button_state, sf::Mouse::Button mouse_button);
        void updateKeyboardButtonsState(ButtonState& current_button_state, sf::Keyboard::Key keyboard_button);
        
    public:
        EventService();
        ~EventService();

        void initialize();
        void update();
        void processEvents();
        
        bool isKeyboardEvent() const;
        bool pressedEscapeKey() const;
        bool pressedLeftKey() const;
        bool pressedRightKey() const;
        bool pressedAKey() const;
        bool pressedDKey() const;
        
        bool pressedLeftMouseButton() const;
        bool pressedRightMouseButton() const;
    };
}