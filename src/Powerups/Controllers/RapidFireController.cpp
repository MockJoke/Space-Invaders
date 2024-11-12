#include "../../../include/Powerup/Controllers/RapidFireController.h"
#include "../../../include/Global/ServiceLocator.h"

namespace Powerup
{
    namespace Controller
    {
        RapidFireController::RapidFireController(PowerupType type) : PowerupController(type) {}

        RapidFireController::~RapidFireController() {}

        void RapidFireController::applyPowerup()
        {
            Global::ServiceLocator::getInstance()->getPlayerService()->enableRapidFire();
        }
    }
}
