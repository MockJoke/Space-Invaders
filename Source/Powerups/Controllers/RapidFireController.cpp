#include "../../header/Powerups/Controllers/RapidFireController.h"

namespace Powerups
{
    namespace Controllers
    {
        RapidFireController::RapidFireController(PowerupType type) : PowerupController(type) {}

        RapidFireController::~RapidFireController() {}

        void RapidFireController::onCollected() {}
    }
}