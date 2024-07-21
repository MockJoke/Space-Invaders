#include "../../header/Powerup/Controllers/TrippleLaserController.h"

namespace Powerup
{
    namespace Controller
    {
        TrippleLaserController::TrippleLaserController(PowerupType type) : PowerupController(type) {}

        TrippleLaserController::~TrippleLaserController() {}

        void TrippleLaserController::onCollected() {}
    }
}