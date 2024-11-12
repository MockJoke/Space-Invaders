#include "../../../include/Powerup/Controllers/ShieldController.h"
#include "../../../include/Global/ServiceLocator.h"

namespace Powerup
{
    namespace Controller
    {
        ShieldController::ShieldController(PowerupType type) : PowerupController(type) {}

        ShieldController::~ShieldController() {}

        void ShieldController::applyPowerup()
        {
            Global::ServiceLocator::getInstance()->getPlayerService()->enableShield();
        }
    }
}
