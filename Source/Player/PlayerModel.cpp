#include "../../Header/Player/PlayerModel.h"

namespace Player
{
    PlayerModel::PlayerModel() { entity_type = Entity::EntityType::PLAYER; }

    PlayerModel::~PlayerModel() { }

    void PlayerModel::initialize() { reset(); }

    void PlayerModel::reset()
    {
        player_state = PlayerState::ALIVE;
        player_position = initial_player_position;
        player_score = 0;
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
}