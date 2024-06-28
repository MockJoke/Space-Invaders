#include "../../Header/UI/Button.h"

namespace UI
{
    Button::Button()
    {
    }

    Button::~Button()
    {
    }

    void Button::Create(const std::string& str, const sf::Font& font, sf::Color color, float size)
    {
        default_color = color;
        highlight_color = sf::Color(128, 128, 128, 225);

        text.setFont(font);
        text.setString(str);
        text.setCharacterSize(size);
        text.setFillColor(default_color);
    }

    void Button::SetPosition(float xPos, float yPos)
    {
        text.setPosition(xPos,yPos);
    }

    bool Button::IsMousePointerOverlapping(sf::Vector2f mousePos) const
    {
        if (text.getGlobalBounds().contains(mousePos.x, mousePos.y))
        {
            return true;
        }
        return false;
    }
    
    void Button::CheckForMouseHover(sf::Vector2f mousePos)
    {
        // Is mouse over button then activate button hover effect
        if (IsMousePointerOverlapping(mousePos))
        {
            text.setFillColor(highlight_color);
        }
        else
        {
            text.setFillColor(default_color);
        }
    }
    
    sf::Vector2f Button::getBounds() const
    {
        return {text.getGlobalBounds().width, text.getGlobalBounds().height};
    }

    sf::Vector2f Button::getPosition() const
    {
        return text.getPosition();
    }

    void Button::Render(sf::RenderWindow* window)
    {
        window->draw(text);
    }
}