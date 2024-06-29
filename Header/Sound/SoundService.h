#pragma once
#include "SFML/Audio.hpp"

namespace Sound
{
    enum class SoundType
    {
        BUTTON_CLICK,
    };

    class SoundService
    {
    private:
        const float background_music_volume = 30.f;

        sf::Music background_music;
        sf::Sound sound_effect;
        sf::SoundBuffer buffer_button_click;

        void loadBackgroundMusicFromFile();
        void loadSoundFromFile();

    public:
        void initialize();

        void playSound(SoundType soundType);
        void playBackgroundMusic();
    };
}