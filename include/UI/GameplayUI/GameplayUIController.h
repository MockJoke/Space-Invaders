#pragma once
#include "../../UI/Interface/IUIController.h"
#include "../../UI/UIElement/ImageView.h"
#include "../../UI/UIElement/ButtonView.h"
#include "../../UI/UIElement/TextView.h"

namespace UI
{
	namespace GameplayUI
	{
		class GameplayUIController : public Interface::IUIController
		{
		private:
			const int font_size = 30;

			const float text_y_position = 15.f;
			const float enemies_killed_text_x_position = 60.f;
			
			const float player_lives_y_offset = 25.f;
			const float player_lives_x_offset = 1850.f;
			const float player_lives_spacing = 60.f;

			const float player_sprite_width = 35.f;
			const float player_sprite_height = 35.f;

			const sf::Color text_color = sf::Color::White;

			UIElement::ImageView* player_image;
			UIElement::TextView* enemies_killed_text;

			void createUIElements();
			void initializeImage() const;
			void initializeText() const;

			void destroy() const;

		public:
			GameplayUIController();
			~GameplayUIController();

			void initialize();
			void update();
			void render();
			void show();

			void updateEnemiesKilledText() const;
			void drawPlayerLives() const;
		};
	}
}