#pragma once
#include "../../header/Powerup/PowerupController.h"

namespace Powerup
{
    namespace Controller
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