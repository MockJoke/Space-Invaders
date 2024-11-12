#include "../../../include/Powerup/Controllers/TripleLaserController.h"
#include "../../../include/Global/ServiceLocator.h"

namespace Powerup
{
    namespace Controller
    {
        TripleLaserController::TripleLaserController(PowerupType type) : PowerupController(type) {}

        TripleLaserController::~TripleLaserController() {}

        void TripleLaserController::applyPowerup()
        {
            Global::ServiceLocator::getInstance()->getPlayerService()->enableTripleLaser();
        }
    }
}
