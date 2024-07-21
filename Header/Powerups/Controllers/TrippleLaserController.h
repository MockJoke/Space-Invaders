#pragma once
#include "../../header/Powerups/PowerupController.h"

namespace Powerups
{
    namespace Controllers
    {
        class TrippleLaserController : public PowerupController
        {
        public:
            TrippleLaserController(PowerupType type);
            virtual ~TrippleLaserController();

            void onCollected() override;
        };
    }
}