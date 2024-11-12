#include "../../include/Player/PlayerModel.h"

namespace Player
{
    int PlayerModel::player_lives = 0;
    int PlayerModel::bullets_fired = 0;
    int PlayerModel::enemies_killed = 0;
    
    PlayerModel::PlayerModel() { entity_type = Entity::EntityType::PLAYER; }

    PlayerModel::~PlayerModel() { }

    void PlayerModel::initialize() { reset(); }

    void PlayerModel::reset()
    {
        player_state = PlayerState::ALIVE;
        player_position = initial_player_position;
        player_lives = max_player_lives;

        enemies_killed = 0;
        bullets_fired = 0;

        b_shield = false;
        b_rapid_fire = false;
        b_triple_laser = false;
    }

    sf::Vector2f PlayerModel::getPlayerPosition() const { return player_position; }

    void PlayerModel::setPlayerPosition(sf::Vector2f position)
    {
        player_position = position;
    }

    PlayerState PlayerModel::getPlayerState() const { return player_state; }

    void PlayerModel::setPlayerState(PlayerState state)
    {
        player_state = state;
    }

    Entity::EntityType PlayerModel::getEntityType() const
    {
        return entity_type;
    }

    void PlayerModel::setEntityType(Entity::EntityType type)
    {
        entity_type = type;
    }

    bool PlayerModel::isShieldEnabled() const
    {
        return b_shield;
    }

    bool PlayerModel::isRapidFireEnabled() const
    {
        return b_rapid_fire;
    }

    bool PlayerModel::isTripleLaserEnabled() const
    {
        return b_triple_laser;
    }

    void PlayerModel::setShieldState(bool value)
    {
        b_shield = value;
    }

    void PlayerModel::setRapidFireState(bool value)
    {
        b_rapid_fire = value;
    }

    void PlayerModel::setTripleFireState(bool value)
    {
        b_triple_laser = value;
    }
}