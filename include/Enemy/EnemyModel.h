﻿#pragma once
#include <SFML/Graphics.hpp>
#include "../Entity/EntityConfig.h"

namespace Enemy
{
    enum class EnemyType;
    enum class EnemyState;
    enum class MovementDirection;
    
    class EnemyModel
    {
    private:
        sf::Vector2f reference_position = sf::Vector2f(50.f, 75.f);
        sf::Vector2f enemy_position;

        Entity::EntityType entity_type;
        EnemyType enemy_type;
        EnemyState enemy_state;
        MovementDirection movement_direction;
        
    public:
        const sf::Vector2f left_most_position = sf::Vector2f(50.f, 75.f);
        const sf::Vector2f right_most_position = sf::Vector2f(1790.f, 75.f);
        const sf::Vector2f barrel_position_offset = sf::Vector2f(30.f, 75.f);
        
        EnemyModel(EnemyType type);
        ~EnemyModel();

        void initialize();

        sf::Vector2f getEnemyPosition() const;
        void setEnemyPosition(sf::Vector2f position);

        sf::Vector2f getReferencePosition() const;
        void setReferencePosition(sf::Vector2f position);

        EnemyType getEnemyType() const;
        void setEnemyType(EnemyType type);
        
        EnemyState getEnemyState() const;
        void setEnemyState(EnemyState type);
        
        MovementDirection getMovementDirection() const;
        void setMovementDirection(MovementDirection direction);

        Entity::EntityType getEntityType() const;
        void setEntityType(Entity::EntityType type);
    };
}