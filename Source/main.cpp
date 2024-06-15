#include "../Header/GameService.h"
// #include <SFML/Graphics.hpp>

// class Player
// {
// private:
//     int health = 3;
//     sf::Vector2f position = sf::Vector2f(585.0f, 300.0f);
//     float movement_speed = 7.5f;
//     int player_score = 0;
//
// public:
//     sf::Texture player_texture;
//     sf::Sprite player_sprite;
//
//     int GetScore() const
//     {
//         return player_score;
//     }
//
//     void SetScore(const int s)
//     {
//         player_score = s;
//     }
//
//     sf::Vector2f GetPosition() const
//     {
//         return position;
//     }
//
//     float GetMoveSpeed() const
//     {
//         return movement_speed;
//     }
//
//     void TakeDamage()
//     {
//     }
//
//     void Move(float offsetX)
//     {
//         position.x += offsetX;
//     }
//
//     void ShootBullets()
//     {
//     }
// };

int main()
{
    // // Define the video mode (dimensions)
    // sf::VideoMode videoMode = sf::VideoMode(1280, 720);
    // // Create a window object with specific dimensions and a title
    // sf::RenderWindow window(videoMode, "Game Window");
    // window.setFramerateLimit(60);
    // window.setPosition(sf::Vector2i(100, 100));
    //
    // Player player;
    //
    // player.player_texture.loadFromFile("assets/textures/player_ship.png");
    // player.player_sprite.setTexture(player.player_texture);
    //
    // while (window.isOpen())
    // {
    //     sf::Event event;
    //
    //     while (window.pollEvent(event))
    //     {
    //         // Check for window closure
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }
    //
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    //     {
    //         player.Move(-1.0f * player.GetMoveSpeed());
    //     }
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    //     {
    //         player.Move(1.0f * player.GetMoveSpeed());
    //     }
    //     
    //     // Clear the window
    //     window.clear(sf::Color::Black);
    //
    //     player.player_sprite.setPosition(player.GetPosition());
    //     window.draw(player.player_sprite);
    //     
    //     // Display whatever you draw
    //     window.display();
    // }

    GameService game_service;
    game_service.ignite();

    while (game_service.isRunning())
    {
        game_service.update();
        game_service.render();
    }

    return 0;
}