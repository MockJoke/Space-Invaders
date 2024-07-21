#include "../../header/Powerups/Controllers/ShieldController.h"

namespace Powerups
{
    namespace Controllers
    {
        ShieldController::ShieldController(PowerupType type) : PowerupController(type) {}

        ShieldController::~ShieldController() {}

        void ShieldController::onCollected() {}
    }
}