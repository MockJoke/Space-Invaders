#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"

namespace UI
{
    UIService::UIService()
    {
        main_menu_controller = nullptr;

        createControllers();
    }

    void UIService::createControllers()
    {
        main_menu_controller = new MainMenu::MainMenuUIController();
    }

    UIService::~UIService()
    {
        destroy();
    }

    void UIService::initialize()
    {
        initializeControllers();
    }

    void UIService::update()
    {
        switch (Main::GameService::getGameState())
        {
        case Main::GameState::MAIN_MENU:
            return main_menu_controller->update();
            break;
        }
    }

    void UIService::render()
    {
        switch (Main::GameService::getGameState())
        {
        case Main::GameState::MAIN_MENU:
            return main_menu_controller->render();;
            break;
        }
    }

    void UIService::initializeControllers()
    {
        main_menu_controller->initialize();
    }

    void UIService::destroy()
    {
        delete(main_menu_controller);
    }
}