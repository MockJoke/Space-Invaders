#pragma once
#include "../../Powerup/PowerupController.h"

namespace Powerup
{
    namespace Controller
    {
        class ShieldController : public PowerupController
        {
        protected:
            void applyPowerup() override;
            
        public:
            ShieldController(PowerupType type);
            virtual ~ShieldController();
        };
    }
}