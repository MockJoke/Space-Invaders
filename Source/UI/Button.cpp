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
        highlight_color = sf::Color(225, 225, 225, 225);

        text.setFont(font);
        text.setString(str);
        text.setCharacterSize(size);
        text.setFillColor(default_color);
    }

    void Button::SetPosition(float xPos, float yPos)
    {
        text.setPosition(xPos,yPos);
    }

    void Button::CheckForMouseHover(sf::Vector2i mousePos)
    {
        // Is mouse over button then activate button hover effect
        if (text.getGlobalBounds().contains(mousePos.x, mousePos.y))
        {
            text.setFillColor(highlight_color);
        }
        else
        {
            text.setFillColor(default_color);
        }
    }

    bool Button::IsPressed(sf::Vector2i mousePos)
    {
        if (text.getGlobalBounds().contains(mousePos.x, mousePos.y))
        {
            text.setFillColor(default_color);
            return true;
        }
        return false;
    }

    sf::Vector2f Button::getBounds() const
    {
        return sf::Vector2f(text.getGlobalBounds().width, text.getGlobalBounds().height);
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