#include "../Header/ServiceLocator.h"

// Constructor: Initializes the graphic_service pointer to null and creates services.
ServiceLocator::ServiceLocator()
{
    graphic_service = nullptr;  // Initialize graphic_service to null
    createServices();   // Call createServices to instantiate services
}

// Destructor: Cleans up resources by clearing all services.
ServiceLocator::~ServiceLocator()
{
    clearAllServices();     // Call clearAllServices to delete any allocated services	
}

void ServiceLocator::createServices()
{
    graphic_service = new GraphicService(); // Dynamically create a GraphicService instance
}

void ServiceLocator::clearAllServices()
{
    delete(graphic_service);    // Delete the graphic_service instance
    graphic_service = nullptr;  // Reset pointer to null to avoid dangling pointer
}

ServiceLocator* ServiceLocator::getInstance()
{
    static ServiceLocator instance;
    return &instance;
}

void ServiceLocator::initialize()
{
    graphic_service->initialize();
}

void ServiceLocator::update()
{
    // Updates all services.
}

void ServiceLocator::render()
{
    // Renders using the services.
}

// Returns a pointer to the currently set graphic service.
GraphicService* ServiceLocator::getGraphicService() const { return graphic_service; }
