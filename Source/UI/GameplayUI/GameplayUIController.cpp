#include "../../header/UI/GameplayUI/GameplayUIController.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Player/PlayerModel.h"

namespace UI
{
    namespace GameplayUI
    {
        GameplayUIController::GameplayUIController() { createUIElements(); }

        GameplayUIController::~GameplayUIController() { destroy(); }

        void GameplayUIController::initialize() 
        {
            initializeImage();
            initializeText();
        }

        void GameplayUIController::createUIElements()
        {
            player_image = new UIElement::ImageView();
            
            enemies_killed_text = new UIElement::TextView();
        }

        void GameplayUIController::initializeImage() const
        {
            player_image->initialize(Global::Config::player_texture_path, player_sprite_width, player_sprite_height, sf::Vector2f(0,0));
        }

        void GameplayUIController::initializeText() const
        {
            sf::String enemies_killed_string = "Enemies Killed : 0";
            
            enemies_killed_text->initialize(enemies_killed_string, sf::Vector2f(enemies_killed_text_x_position, text_y_position), UIElement::FontType::ARCADE_N, font_size, text_color);
        }

        void GameplayUIController::update()
        {
            updateEnemiesKilledText();
        }

        void GameplayUIController::render()
        {
            enemies_killed_text->render();
            drawPlayerLives();
        }

        void GameplayUIController::show() { }

        void GameplayUIController::updateEnemiesKilledText() const
        {
            sf::String enemies_killed_string = "Enemies Killed : " + std::to_string(Player::PlayerModel::enemies_killed);
            enemies_killed_text->setText(enemies_killed_string);
        }

        void GameplayUIController::drawPlayerLives() const
        {
            sf::RenderWindow* game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            for (int i = 0; i < Player::PlayerModel::player_lives; i++)
            {
                player_image->setPosition(sf::Vector2f(player_lives_x_offset - (i * player_lives_spacing), player_lives_y_offset));
                player_image->render();
            }
        }

        void GameplayUIController::destroy() const
        {
            delete(player_image);
            delete(enemies_killed_text);
        }
    }
}