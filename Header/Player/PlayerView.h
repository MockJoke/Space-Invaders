﻿#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Player/PlayerController.h"

class PlayerView
{
private:
    const sf::String player_texture_path = "assets/textures/player_ship.png";
    const float player_sprite_width = 60.0f;
    const float player_sprite_height = 60.0f;

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