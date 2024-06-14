#include <SFML/Graphics.hpp>

class Player
{
private:
    int health = 3;
    sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
    int movement_speed = 5;
    int player_score = 0;

public:
    sf::Texture player_texture;
    sf::Sprite player_sprite;

    int getScore() const
    {
        return player_score;
    }

    void setScore(const int s)
    {
        player_score = s;
    }

    void takeDamage()
    {
    }

    void move()
    {
    }

    void shootBullets()
    {
    }
};

int main()
{
    // Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(1280, 720);
    //sf::VideoMode videoMode = *(new sf::VideoMode(800, 600)); sf::RenderWindow* window = new sf::RenderWindow(videoMode, "My SFML Window");

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "Game Window");
    //sf::RenderWindow window(sf::VideoMode(1280, 720), "Resizable Window", sf::Style::Resize);
    //sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Fullscreen Window", sf::Style::Fullscreen);
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(100, 100));

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear(sf::Color::Black);
        
        // Display whatever you draw
        window.display();
    }

    return 0;
}