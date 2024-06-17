#pragma once
#include "../Graphic/GraphicService.h"
#include "../Event/EventService.h"
#include "../Player/PlayerService.h"
#include "../Time/TimeService.h"

/* Class Summary
    This class manages access to various services in the application
*/
class ServiceLocator
{
private:
    GraphicService* graphic_service;
    TimeService* time_service;
    EventService* event_service;
    PlayerService* player_service;

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
    GraphicService* getGraphicService() const;
    TimeService* getTimeService() const;
    EventService* getEventService() const;
    PlayerService* getPlayerService() const;
};