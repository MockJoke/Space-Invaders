#pragma once

namespace Bullet
{
    enum class BulletType
    {
        PLAYER_BULLET,
        LASER_BULLET,
        TORPEDO,
        FROST_BULLET,
    };

    enum class MovementDirection
    {
        UP,
        DOWN,
    };
}