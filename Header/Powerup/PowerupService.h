#pragma once
#include <vector>
#include "SFML/System/Vector2.hpp"
#include "../../Header/Collectible/ICollectible.h"

namespace Powerup
{
    class PowerupController;
    enum class PowerupType;

    class PowerupService
    {
    private:
        std::vector<Collectible::ICollectible*> powerup_list;

        PowerupController* createPowerup(PowerupType powerup_type);
        void destroy() const;

    public:
        PowerupService();
        virtual ~PowerupService();

        static void initialize();
        void update() const;
        void render() const;

        PowerupController* spawnPowerup(PowerupType powerup_type, sf::Vector2f position);
        void destroyPowerup(PowerupController* powerup_controller);
    };
}