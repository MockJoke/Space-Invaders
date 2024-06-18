#include "../../Header/Global/ServiceLocator.h"

namespace Global
{
    // Constructor: Initializes the graphic_service pointer to null and creates services.
    ServiceLocator::ServiceLocator()
    {
        // Initialize service to null
        graphic_service = nullptr;
        time_service = nullptr;
        event_service = nullptr;
        player_service = nullptr;
        ui_service = nullptr;
        
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
        player_service = new Player::PlayerService();
        ui_service = new UI::UIService();
    }

    void ServiceLocator::clearAllServices()
    {
        // Delete the service instance
        delete(graphic_service);
        delete(time_service);
        delete(event_service);
        delete(player_service);
        delete(ui_service);
        
        // Reset pointer to null to avoid dangling pointer
        graphic_service = nullptr;
        time_service = nullptr;
        event_service = nullptr;
        player_service = nullptr;
        ui_service = nullptr;
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
        player_service->initialize();
        ui_service->initialize();
    }

    void ServiceLocator::update()
    {
        // Updates all services
        graphic_service->update();
        time_service->update();
        event_service->update();
        player_service->update();
        ui_service->update();
    }

    void ServiceLocator::render()
    {
        // Renders using the services
        graphic_service->render();
        player_service->render();
        ui_service->render();
    }

    // Returns a pointer to the currently set graphic service
    Graphic::GraphicService* ServiceLocator::getGraphicService() const { return graphic_service; }
    Time::TimeService* ServiceLocator::getTimeService() const { return time_service; }
    Event::EventService* ServiceLocator::getEventService() const { return event_service; }
    Player::PlayerService* ServiceLocator::getPlayerService() const { return player_service; }
    UI::UIService* ServiceLocator::getUIService() const { return ui_service; }
}