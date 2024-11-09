#pragma once
#include "../UI/UIElement/ImageView.h"

namespace Player
{
    class PlayerController;

    class PlayerView
    {
    private:
        const float player_sprite_width = 80.f;
        const float player_sprite_height = 80.f;

        PlayerController* player_controller;
        UI::UIElement::ImageView* player_image;

        void createUIElements();
        void initializeImage() const;

        void destroy() const;

    public:
        PlayerView();
        ~PlayerView();

        void initialize(PlayerController* controller);
        void update() const;
        void render() const;

        void setPlayerHighlight(bool b_highlight) const;
        const sf::Sprite& getPlayerSprite() const;
    };    
}
