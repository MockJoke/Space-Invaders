#include "../../include/Graphic/GraphicService.h"

namespace Graphic
{
	GraphicService::GraphicService()
	{
		game_window = nullptr;
		video_mode = nullptr;
	}

	GraphicService::~GraphicService() { onDestroy(); }

	void GraphicService::initialize()
	{
		game_window = createGameWindow();
		// setFrameRate(frame_rate);
	}

	sf::RenderWindow* GraphicService::createGameWindow()
	{
		setVideoMode();
		return new sf::RenderWindow(*video_mode, game_window_title, sf::Style::Fullscreen);
	}

	// Sets up the video mode for the game window using specified dimensions and system's color depth
	void GraphicService::setVideoMode()
	{
		video_mode = new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel);
	}
	
	void GraphicService::update() { }
	
	void GraphicService::render() { }
	
	bool GraphicService::isGameWindowOpen() const { return game_window->isOpen();	}
	
	sf::RenderWindow* GraphicService::getGameWindow() const { return game_window; }
	
	sf::Color GraphicService::getWindowColor() const { return window_color; }

	void GraphicService::setFrameRate(int frame_rate_to_set) const
	{
		game_window->setFramerateLimit(frame_rate_to_set);
	}

	void GraphicService::onDestroy() const
	{
		delete (video_mode);
		delete (game_window);
	}
}