#include "../../header/Powerup/Controllers/TrippleLaserController.h"
#include "../../../Header/Global/ServiceLocator.h"

namespace Powerup
{
    namespace Controller
    {
        TrippleLaserController::TrippleLaserController(PowerupType type) : PowerupController(type) {}

        TrippleLaserController::~TrippleLaserController() {}

        void TrippleLaserController::applyPowerup()
        {
            Global::ServiceLocator::getInstance()->getPlayerService()->enableTripleLaser();
        }
    }
}
