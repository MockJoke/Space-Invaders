#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"

namespace UI
{
    UIService::UIService()
    {
        main_menu_controller = nullptr;
        gameplay_ui_controller = nullptr;
        splash_screen_ui_controller = nullptr;

        createControllers();
    }

    void UIService::createControllers()
    {
        main_menu_controller = new MainMenu::MainMenuUIController();
        gameplay_ui_controller = new GameplayUI::GameplayUIController();
        splash_screen_ui_controller = new SplashScreen::SplashScreenUIController();
    }

    UIService::~UIService()
    {
        destroy();
    }

    void UIService::initialize() const
    {
        UIElement::TextView::initializeTextView();
        initializeControllers();
    }

    void UIService::update()
    {
        Interface::IUIController* ui_controller = getCurrentUIController();
        
        if (ui_controller)
            ui_controller->update();
    }

    void UIService::render()
    {
        Interface::IUIController* ui_controller = getCurrentUIController();
        
        if (ui_controller)
            ui_controller->render();
    }

    void UIService::showScreen()
    {
        Interface::IUIController* ui_controller = getCurrentUIController();

        if (ui_controller)
            ui_controller->show();
    }
    
    void UIService::initializeControllers() const
    {
        main_menu_controller->initialize();
        gameplay_ui_controller->initialize();
        splash_screen_ui_controller->initialize();
    }

    Interface::IUIController* UIService::getCurrentUIController() const
    {
        switch (Main::GameService::getGameState())
        {
        case Main::GameState::MAIN_MENU:
            return main_menu_controller;

        case Main::GameState::SPLASH_SCREEN:
            return splash_screen_ui_controller;

        case Main::GameState::GAMEPLAY:
            return gameplay_ui_controller;

        default:
            return nullptr;
        }
    }

    void UIService::destroy() const
    {
        delete(main_menu_controller);
        delete(gameplay_ui_controller);
        delete(splash_screen_ui_controller);
    }
}