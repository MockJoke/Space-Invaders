#pragma once
#include <SFML/Graphics.hpp>
#include "../Global/Config.h"

namespace Player
{
    class PlayerController;

    class PlayerView
    {
    private:
        const sf::String player_texture_path = Global::Config::player_texture_path;
        const float player_sprite_width = 80.f;
        const float player_sprite_height = 80.f;

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
