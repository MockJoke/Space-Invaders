#pragma once
#include "../../header/Powerups/PowerupController.h"

namespace Powerups
{
    namespace Controllers
    {
        class ShieldController : public PowerupController
        {
        public:
            ShieldController(PowerupType type);
            virtual ~ShieldController();

            void onCollected() override;
        };
    }
}