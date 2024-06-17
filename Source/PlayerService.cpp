#include "../Header/PlayerService.h"
#include "../Header/ServiceLocator.h"

PlayerService::PlayerService()
{
    game_window = nullptr;
}

PlayerService::~PlayerService() = default;

void PlayerService::initialize() 
{
    game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
    initializePlayerSprite();	
}

//take our players input in update, then set the position.
//order is important here
void PlayerService::update()
{
    processPlayerInput();
    player_sprite.setPosition(getPosition());
}

void PlayerService::render()
{
    game_window->draw(player_sprite);
}

void PlayerService::processPlayerInput()
{
    const EventService* event_service = ServiceLocator::getInstance()->getEventService();

    // Check if a key has been pressed
    if (event_service->isKeyboardEvent())
    {
        if (event_service->pressedLeftKey())
        {
            moveLeft();
        }
      
        if (event_service->pressedRightKey())
        {
            moveRight();
        }
    }
}

void PlayerService::initializePlayerSprite()
{
    if (player_texture.loadFromFile(player_texture_path))
    {
        player_sprite.setTexture(player_texture);
    }
}

void PlayerService::moveLeft()
{
    position.x -= movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
}

void PlayerService::moveRight()
{
    position.x += movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
}

sf::Vector2f PlayerService::getPosition() const { return position; }
float PlayerService::getMoveSpeed() const { return movement_speed; }