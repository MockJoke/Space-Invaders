#include "../../header/Powerup/Controllers/RapidFireController.h"

#include "../../../Header/Global/ServiceLocator.h"

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
