#include "../../header/Powerups/Controllers/TrippleLaserController.h"

namespace Powerups
{
    namespace Controllers
    {
        TrippleLaserController::TrippleLaserController(PowerupType type) : PowerupController(type) {}

        TrippleLaserController::~TrippleLaserController() {}

        void TrippleLaserController::onCollected() {}
    }
}