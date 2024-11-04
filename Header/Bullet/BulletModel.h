#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/Entity/EntityConfig.h"

namespace Bullet
{
    enum class BulletType;
    enum class MovementDirection;

    class BulletModel
    {
    private:
        float movement_speed = 300.f;
        sf::Vector2f bullet_position;

        BulletType bullet_type;
        Entity::EntityType entity_type;
        MovementDirection movement_direction;

    public:
        BulletModel(BulletType type, Entity::EntityType entity_type);
        ~BulletModel();

        void initialize(sf::Vector2f position, MovementDirection direction);

        sf::Vector2f getBulletPosition() const;
        void setBulletPosition(sf::Vector2f position);

        BulletType getBulletType() const;
        void setBulletType(BulletType type);

        Entity::EntityType getEntityType() const;
        void setEntityType(Entity::EntityType type);

        MovementDirection getMovementDirection() const;
        void setMovementDirection(MovementDirection direction);

        float getMovementSpeed() const;
        void setMovementSpeed(float speed);
    };
}