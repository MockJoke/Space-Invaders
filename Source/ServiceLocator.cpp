#include "../Header/ServiceLocator.h"

void ServiceLocator::createServices()
{
    // Creates instances of all services.
}

void ServiceLocator::clearAllServices()
{
    // Deletes and deallocates memory for all services
}

ServiceLocator* ServiceLocator::getInstance()
{
    static ServiceLocator instance;
    return &instance;
    // Provides a method to access the unique ServiceLocator instance (object)
}

void ServiceLocator::initialize()
{
    //	Initializes the ServiceLocator.
}

void ServiceLocator::update()
{
    // Updates all services.
}

void ServiceLocator::render()
{
    // Renders using the services.
}