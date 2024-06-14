#include <SFML/Graphics.hpp>

class Player
{
private:
    int health = 3;
    sf::Vector2f position = sf::Vector2f(585.f, 300.f);
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

    sf::Vector2f getPosition() const
    {
        return position;
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

    Player player;

    player.player_texture.loadFromFile("assets/textures/player_ship.png");
    player.player_sprite.setTexture(player.player_texture);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            player.move();
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            player.move();    
        }
        
        // Clear the window
        window.clear(sf::Color::Black);

        player.player_sprite.setPosition(player.getPosition()); // Set the position of the player sprite

        window.draw(player.player_sprite);    // Draw the player sprite
        
        // Display whatever you draw
        window.display();
    }

    return 0;
}