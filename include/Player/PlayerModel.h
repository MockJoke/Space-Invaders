#pragma once
#include <SFML/Graphics.hpp>
#include "../Entity/EntityConfig.h"
#include "../UI/GameplayUI/GameplayUIController.h"

namespace Player
{
    enum class PlayerState
    {
        ALIVE,
        FROZEN,
        DEAD,
    };

    class PlayerModel
    {
    private:
        friend class PlayerController;

        friend void UI::GameplayUI::GameplayUIController::updateEnemiesKilledText() const;
        friend void UI::GameplayUI::GameplayUIController::drawPlayerLives() const;
        
        const sf::Vector2f initial_player_position = sf::Vector2f(950.0f, 950.0f);
        const int max_player_lives = 3;
        
        sf::Vector2f player_position;
        PlayerState player_state;
        Entity::EntityType entity_type;

        static int player_lives;
        static int player_score;
        static int enemies_killed;
        static int bullets_fired;

        bool b_shield;
        bool b_rapid_fire;
        bool b_triple_laser;

    public:
        const sf::Vector2f left_most_position = sf::Vector2f(50.0f, 950.f);
        const sf::Vector2f right_most_position = sf::Vector2f(1770.0f, 950.f);
        const sf::Vector2f barrel_position_offset = sf::Vector2f(30.f, 10.f);
        const sf::Vector2f second_weapon_position_offset = sf::Vector2f(50.f, 10.f);
        const sf::Vector2f third_weapon_position_offset = sf::Vector2f(-50.f, 10.f);
    
        const float player_movement_speed = 350.0f;

        const float shiled_powerup_duration = 10.f;
        const float rapid_fire_powerup_duration = 10.f;
        const float triple_laser_powerup_duration = 10.f;

        const float freeze_duration = 1.5f;

        const float fire_cooldown_duration = 0.2f;
        const float rapid_fire_cooldown_duration = 0.05f;
        const float triple_laser_position_offset = 30.f;

        static const int invincible_player_alpha = 170.f;

        PlayerModel();
        ~PlayerModel();

        void initialize();
        void reset();

        sf::Vector2f getPlayerPosition() const;
        void setPlayerPosition(sf::Vector2f position);

        PlayerState getPlayerState() const;
        void setPlayerState(PlayerState state);

        Entity::EntityType getEntityType() const;
        void setEntityType(Entity::EntityType type);

        bool isShieldEnabled() const;
        bool isRapidFireEnabled() const;
        bool isTripleLaserEnabled() const;

        void setShieldState(bool value);
        void setRapidFireState(bool value);
        void setTripleFireState(bool value);
    };    
}