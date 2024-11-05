#pragma once

#include <SFML/Graphics.hpp>

namespace Graphic
{
    class GraphicService
    {
    private:
        const std::string game_window_title = "Space Invaders"; 

        const int frame_rate = 60;
        
        const int game_window_width = 1920;
        const int game_window_height = 1080;
        const sf::Color window_color = sf::Color::Black;

        sf::VideoMode* video_mode;
        sf::RenderWindow* game_window;

        void setVideoMode();
        void onDestroy() const;

    public:
        GraphicService();
        ~GraphicService();

        sf::RenderWindow* createGameWindow();
    
        void initialize();
        void update();
        void render();
        bool isGameWindowOpen() const;
	
        sf::RenderWindow* getGameWindow() const;
        sf::Color getWindowColor() const;

        void setFrameRate(int) const;
    };
}