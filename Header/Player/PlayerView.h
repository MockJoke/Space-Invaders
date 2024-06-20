#pragma once
#include <SFML/Graphics.hpp>

namespace Player
{
    class PlayerController;

    class PlayerView
    {
    private:
        const sf::String player_texture_path = "Assets/Textures/player_ship.png";
        const float player_sprite_width = 80.f;
        const float player_sprite_height = 40.0f;

        sf::RenderWindow* game_window;
    
        sf::Texture player_texture;
        sf::Sprite player_sprite;

        PlayerController* player_controller; // ptr to player controller

        void initializePlayerSprite();
        void scalePlayerSprite();

    public:
        PlayerView();
        ~PlayerView();

        void initialize(PlayerController* controller);
        void update();
        void render();
    };    
}