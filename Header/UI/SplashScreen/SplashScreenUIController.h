#pragma once
#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/AnimatedImageView.h"

namespace UI
{
	namespace SplashScreen
	{
		class SplashScreenUIController : public Interface::IUIController
		{
		private:
			const float logo_animation_duration = 2.0f;
			const float logo_width = 196.25f;
			const float logo_height = 148.75f;

			UIElement::AnimatedImageView* game_logo_view;

			void initializeGameLogo();
			void fadeInAnimationCallback();
			void fadeOutAnimationCallback();
			sf::Vector2f getLogoPosition() const;

		public:
			SplashScreenUIController();
			~SplashScreenUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}