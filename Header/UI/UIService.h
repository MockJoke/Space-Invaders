﻿#pragma once
#include "../../Header/UI/MainMenu/MainMenuController.h"
#include "../../header/UI/SplashScreen/SplashScreenUIController.h"
#include "../../header/UI/GameplayUI/GameplayUIController.h"
#include "../../header/UI/Interface/IUIController.h"

namespace UI
{
    class UIService
    {
    private:
        MainMenu::MainMenuUIController* main_menu_controller;
        GameplayUI::GameplayUIController* gameplay_ui_controller;
        SplashScreen::SplashScreenUIController* splash_screen_ui_controller;

        void createControllers();
        void initializeControllers() const;
        Interface::IUIController* getCurrentUIController() const;
        void destroy() const;

    public:
        UIService();
        ~UIService();

        void initialize() const;
        void update();
        void render();
        void showScreen();
    };
}
