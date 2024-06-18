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
    }

    void UIService::render()
    {
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