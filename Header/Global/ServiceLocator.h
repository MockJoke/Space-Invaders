#pragma once
#include "../Enemy/EnemyService.h"
#include "../Graphic/GraphicService.h"
#include "../Event/EventService.h"
#include "../Gameplay/GameplayService.h"
#include "../Player/PlayerService.h"
#include "../Time/TimeService.h"
#include "../UI/UIService.h"
#include "../Element/ElementService.h"

namespace Global
{
    /* Class Summary
    This class manages access to various services in the application
*/
    class ServiceLocator
    {
    private:
        Graphic::GraphicService* graphic_service;
        Time::TimeService* time_service;
        Event::EventService* event_service;
        UI::UIService* ui_service;
        Gameplay::GameplayService* gameplay_service;
        Player::PlayerService* player_service;
        Enemy::EnemyService* enemy_service;
        Element::ElementService* element_service;

        // Private Constructor and Destructor:
    
        // Constructor for initializing the ServiceLocator
        ServiceLocator(); 
    
        // Destructor for cleaning up resources upon object deletion
        ~ServiceLocator(); 	

        // Private Methods:
        void createServices(); 			// Creates instances of all services
        void clearAllServices(); 		//	Deletes and deallocates memory for all services

    public:
        // Public Methods:
        static ServiceLocator* getInstance();  // Provides a method to access the unique ServiceLocator instance (object)

        void initialize(); 			//	Initializes the ServiceLocator
        void update(); 				//	Updates all services
        void render(); 				//	Renders using the services

        // Methods to Get Specific Services: 
        Graphic::GraphicService* getGraphicService() const;
        Time::TimeService* getTimeService() const;
        Event::EventService* getEventService() const;
        UI::UIService* getUIService() const;
        Gameplay::GameplayService* getGameplayService() const;
        Player::PlayerService* getPlayerService() const;
        Enemy::EnemyService* getEnemyService() const;
        Element::ElementService* getElementService() const;
    };
}
