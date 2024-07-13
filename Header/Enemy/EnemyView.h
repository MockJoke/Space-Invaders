#pragma once
#include <SFML/Graphics.hpp>
#include "EnemyConfig.h"
#include "../../Header/Global/Config.h"

namespace Enemy
{
    class EnemyController;

    class EnemyView
    {
    private:
        const sf::String subzero_texture_path = Global::Config::subzero_texture_path;
        const sf::String zapper_texture_path = Global::Config::zapper_texture_path;
        const sf::String thunder_snake_texture_path = Global::Config::thunder_snake_texture_path;

        const float enemy_sprite_width = 80.f;
        const float enemy_sprite_height = 80.f;

        EnemyController* enemy_controller;

        sf::RenderWindow* game_window;
        sf::Texture enemy_texture;
        sf::Sprite enemy_sprite;

        void initializeEnemySprite(EnemyType type);
        void scaleEnemySprite();

    public:
        EnemyView();
        ~EnemyView();

        void initialize(EnemyController* controller);
        void update();
        void render();
    };
}
