#include "../../Header/UI/MainMenu/MainMenuController.h"
// #include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"

namespace UI
{
    // Nested namespace since everything in MainMenu exists inside UI
    namespace MainMenu
    {
        MainMenuUIController::MainMenuUIController() { game_window = nullptr; }

        void MainMenuUIController::initialize()
        {
            game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
        }

        void MainMenuUIController::update()
        {
        }

        void MainMenuUIController::render()
        {
        }
    }
}