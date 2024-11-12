#include "../../include/Event/EventService.h"
#include "../../include/Main/GameService.h"
#include "../../include/Graphic/GraphicService.h"

namespace Event
{
    EventService::EventService()
    {
        game_window = nullptr;
    }

    EventService::~EventService() = default;

    void EventService::initialize()
    {
        game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
    }

    void EventService::update()
    {
        updateMouseButtonsState(left_mouse_button_state, sf::Mouse::Left);
        updateMouseButtonsState(right_mouse_button_state, sf::Mouse::Right);
        updateKeyboardButtonsState(left_arrow_button_state, sf::Keyboard::Left);
        updateKeyboardButtonsState(right_arrow_button_state, sf::Keyboard::Right);
        updateKeyboardButtonsState(A_button_state, sf::Keyboard::A);
        updateKeyboardButtonsState(D_button_state, sf::Keyboard::D);
    }

    void EventService::updateMouseButtonsState(ButtonState& current_button_state, sf::Mouse::Button mouse_button)
    {
        if (sf::Mouse::isButtonPressed(mouse_button))
        {
            switch (current_button_state)
            {
            case ButtonState::RELEASED:
                current_button_state = ButtonState::PRESSED;
                break;
            case ButtonState::PRESSED:
                current_button_state = ButtonState::HELD;
                break;
            }
        }
        else
        {
            current_button_state = ButtonState::RELEASED;
        }
    }

    void EventService::updateKeyboardButtonsState(ButtonState& current_button_state, sf::Keyboard::Key keyboard_button)
    {
        if (sf::Keyboard::isKeyPressed(keyboard_button))
        {
            switch (current_button_state)
            {
            case ButtonState::RELEASED:
                current_button_state = ButtonState::PRESSED;
                break;
            case ButtonState::PRESSED:
                current_button_state = ButtonState::HELD;
                break;
            }
        }
        else
        {
            current_button_state = ButtonState::RELEASED;
        }
    }
    
    void EventService::processEvents()
    {
        if (isGameWindowOpen())
        {
            while (game_window->pollEvent(game_event))
            {
                // Check for window closure
                if (gameWindowWasClosed() || hasQuitGame())
                {
                    game_window->close();
                }
            }
        }
    }

    bool EventService::hasQuitGame() const
    {
        // only true if the ESC key is pressed and a keyboard event has been registered
        return (isKeyboardEvent() && pressedEscapeKey());
    }

    bool EventService::isGameWindowOpen() const { return game_window != nullptr; }

    bool EventService::gameWindowWasClosed() const { return game_event.type == sf::Event::Closed; }

    // Checks for if a keyboard key has been pressed
    bool EventService::isKeyboardEvent() const { return game_event.type == sf::Event::KeyPressed; }

    bool EventService::pressedEscapeKey() const { return game_event.key.code == sf::Keyboard::Escape; }

    bool EventService::pressedLeftKey() const { return left_arrow_button_state == ButtonState::HELD; }

    bool EventService::pressedRightKey() const { return right_arrow_button_state == ButtonState::HELD; }

    bool EventService::pressedAKey() const { return A_button_state == ButtonState::HELD; }

    bool EventService::pressedDKey() const { return D_button_state == ButtonState::HELD; }

    bool EventService::pressedLeftMouseButton() const { return left_mouse_button_state == ButtonState::PRESSED; }

    bool EventService::pressedRightMouseButton() const { return right_mouse_button_state == ButtonState::PRESSED; }
}
