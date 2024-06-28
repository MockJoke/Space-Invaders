#pragma once
#include <SFML/Graphics.hpp>
#include "EnemyConfig.h"

namespace Enemy
{
    class EnemyController;

    class EnemyView
    {
    private:
        const sf::String subzero_texture_path = "Assets/Textures/subzero.png";
        const sf::String zapper_texture_path = "Assets/Textures/zapper.png";

        const float enemy_sprite_width = 80.f;
        const float enemy_sprite_height = 60.f;

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
