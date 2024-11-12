#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../Elements/Bunker/BunkerController.h"
#include "../Elements/Bunker/BunkerModel.h"

namespace Element
{
    class ElementService
    {
    private:
        const std::vector<Bunker::BunkerData> bunker_data_list = {  Bunker::BunkerData(sf::Vector2f(150.f, 800.f)),
                                                                    Bunker::BunkerData(sf::Vector2f(425.0f, 800.f)),
                                                                    Bunker::BunkerData(sf::Vector2f(700.0f, 800.f)),
                                                                    Bunker::BunkerData(sf::Vector2f(1120.0f, 800.f)),
                                                                    Bunker::BunkerData(sf::Vector2f(1395.0f, 800.f)),
                                                                    Bunker::BunkerData(sf::Vector2f(1670.0f, 800.f)) };
        
        std::vector<Bunker::BunkerController*> bunker_list;
        std::vector<Bunker::BunkerController*> flagged_bunker_list;

        void spawnBunkers();
        void destroyFlaggedBunkers();

        void destroy();
        
    public:
        ElementService();
        ~ElementService();

        void initialize();
        void update();
        void render();

        void reset();

        void destroyBunker(Bunker::BunkerController* bunker_controller);
    };    
}
