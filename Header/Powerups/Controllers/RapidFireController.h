#pragma once
#include "../../header/Powerups/PowerupController.h"

namespace Powerups
{
    namespace Controllers
    {
        class RapidFireController : public PowerupController
        {
        public:
            RapidFireController(PowerupType type);
            virtual ~RapidFireController();

            void onCollected() override;
        };
    }
}