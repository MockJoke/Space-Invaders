#pragma once
#include <SFML/Graphics.hpp>

namespace UI
{
    class Button
    {
    private:
        std::string name;
        sf::Text text;

        sf::Color default_color;
        sf::Color highlight_color;

    public:
        //constructor and destructors
        Button();
        ~Button();

        void Create(const std::string& str, const sf::Font& font, sf::Color color, float size);
        void SetPosition(float xPos, float yPos);
	
        // Mouse input
        void CheckForMouseHover(sf::Vector2i mousePos);
        bool IsPressed(sf::Vector2i mousePos);
	
        sf::Vector2f getBounds() const;
        sf::Vector2f getPosition() const;

        void Render(sf::RenderWindow* window);
    };    
}
