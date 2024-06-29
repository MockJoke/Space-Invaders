#pragma once
#include <SFML/Graphics.hpp>
#include "../Global/Config.h"

namespace Gameplay
{
    class GameplayView
    {
    private:
        const sf::String background_texture_path = Global::Config::background_texture_path;

        sf::RenderWindow* game_window;
        sf::Texture background_texture;
        sf::Sprite background_sprite;

        void initializeBackgroundSprite();
        void scaleBackgroundSprite();

    public:
        GameplayView();
        ~GameplayView();

        void initialize();
        void update();
        void render();
    };
}
