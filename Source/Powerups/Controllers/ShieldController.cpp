#include "../../header/Powerup/Controllers/ShieldController.h"

#include "../../../Header/Global/ServiceLocator.h"

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
