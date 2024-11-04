#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"

namespace Enemy
{
    EnemyModel::EnemyModel(EnemyType type)
    {
        enemy_type = type;
    }

    EnemyModel::~EnemyModel() { }

    void EnemyModel::initialize()
    {
        enemy_state = EnemyState::PATROLLING;
        movement_direction = MovementDirection::RIGHT;
        enemy_position = reference_position;
    }

    sf::Vector2f EnemyModel::getEnemyPosition() const
    {
        return enemy_position;
    }

    void EnemyModel::setEnemyPosition(sf::Vector2f position)
    {
        enemy_position = position;
    }

    sf::Vector2f EnemyModel::getReferencePosition() const
    {
        return reference_position;
    }

    void EnemyModel::setReferencePosition(sf::Vector2f position)
    {
        reference_position = position;
    }

    EnemyType EnemyModel::getEnemyType() const
    {
        return enemy_type;
    }

    void EnemyModel::setEnemyType(EnemyType type)
    {
        enemy_type = type;
    }

    EnemyState EnemyModel::getEnemyState() const
    {
        return enemy_state;
    }

    void EnemyModel::setEnemyState(EnemyState state)
    {
        enemy_state = state;
    }
    
    MovementDirection EnemyModel::getMovementDirection() const
    {
        return movement_direction;
    }

    void EnemyModel::setMovementDirection(MovementDirection direction)
    {
        movement_direction = direction;
    }

    Entity::EntityType EnemyModel::getEntityType() const
    {
        return entity_type;
    }

    void EnemyModel::setEntityType(Entity::EntityType type)
    {
        entity_type = type;
    }
}