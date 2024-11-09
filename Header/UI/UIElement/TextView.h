#pragma once
#include "../../UI/UIElement/UIView.h"

namespace UI
{
    namespace UIElement
    {
        enum class FontType
        {
            ARCADE_I,
            ARCADE_N,
        };

        class TextView : public UIView
        {
        private:
            static const int default_font_size = 55;

            static sf::Font font_ArcadeI;
            static sf::Font font_ArcadeN;
            
            sf::Text text;
            static void loadFont();

        public:
            TextView();
            virtual ~TextView();

            static void initializeTextView();

            virtual void initialize(sf::String text_value, sf::Vector2f position, FontType font_type = FontType::ARCADE_N, int font_size = default_font_size, sf::Color color = sf::Color::White);
            virtual void update() override;
            virtual void render() override;

            void setFont(FontType font_type);
            void setFontSize(int font_size);
            void setTextPosition(sf::Vector2f position);
            void setTextColor(sf::Color color);
            void setText(sf::String text_value);
            void setTextCentreAligned();
        };
    }
}