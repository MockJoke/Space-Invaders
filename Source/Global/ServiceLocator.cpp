#include "../../Header/Global/ServiceLocator.h"

#include "../../Header/Main/GameService.h"

namespace Global
{
    // Constructor: Initializes the graphic_service pointer to null and creates services.
    ServiceLocator::ServiceLocator()
    {
        // Initialize service to null
        graphic_service = nullptr;
        time_service = nullptr;
        event_service = nullptr;
        ui_service = nullptr;
        gameplay_service = nullptr;
        player_service = nullptr;
        enemy_service = nullptr;
        
        createServices();   // Call createServices to instantiate services
    }

    // Destructor: Cleans up resources by clearing all services
    ServiceLocator::~ServiceLocator()
    {
        clearAllServices();     // Call clearAllServices to delete any allocated services	
    }

    void ServiceLocator::createServices()
    {
        // Dynamically create a service instance
        graphic_service = new Graphic::GraphicService();
        time_service = new Time::TimeService();
        event_service = new Event::EventService();
        ui_service = new UI::UIService();
        gameplay_service = new Gameplay::GameplayService();
        player_service = new Player::PlayerService();
        enemy_service = new Enemy::EnemyService();
    }

    void ServiceLocator::clearAllServices()
    {
        // Delete the service instance
        delete(graphic_service);
        delete(time_service);
        delete(event_service);
        delete(ui_service);
        delete(gameplay_service);
        delete(player_service);
        delete(enemy_service);
        
        // Reset pointer to null to avoid dangling pointer
        graphic_service = nullptr;
        time_service = nullptr;
        event_service = nullptr;
        ui_service = nullptr;
        gameplay_service = nullptr;
        player_service = nullptr;
        enemy_service = nullptr;
    }

    ServiceLocator* ServiceLocator::getInstance()
    {
        static ServiceLocator instance;
        return &instance;
    }

    void ServiceLocator::initialize()
    {
        graphic_service->initialize();
        time_service->initialize();
        event_service->initialize();
        ui_service->initialize();
        gameplay_service->initialize();
        player_service->initialize();
        enemy_service->initialize();
    }

    void ServiceLocator::update()
    {
        // Updates all services
        graphic_service->update();
        time_service->update();
        event_service->update();

        ui_service->update();
        
        if (Main::GameService::getGameState() == Main::GameState::GAMEPLAY)
        {
            gameplay_service->update();
            player_service->update();
            enemy_service->update();
        }
    }

    void ServiceLocator::render()
    {
        // Renders using the services
        graphic_service->render();
        
        ui_service->render();
        
        if (Main::GameService::getGameState() == Main::GameState::GAMEPLAY)
        {
            gameplay_service->render();
            player_service->render();
            enemy_service->render();
        }
    }

    // Returns a pointer to the currently set graphic service
    Graphic::GraphicService* ServiceLocator::getGraphicService() const { return graphic_service; }
    Time::TimeService* ServiceLocator::getTimeService() const { return time_service; }
    Event::EventService* ServiceLocator::getEventService() const { return event_service; }
    UI::UIService* ServiceLocator::getUIService() const { return ui_service; }
    Gameplay::GameplayService* ServiceLocator::getGameplayService() const { return gameplay_service; }
    Player::PlayerService* ServiceLocator::getPlayerService() const { return player_service; }
    Enemy::EnemyService* ServiceLocator::getEnemyService() const { return enemy_service; }
}
