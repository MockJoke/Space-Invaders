#pragma once
#include "SFML/Audio.hpp"

namespace Sound
{
    enum class SoundType
    {
        BUTTON_CLICK,

        BULLET_FIRE,
        EXPLOSION,
        POWERUP_ENABLED,
        POWERUP_DISABLED,
    };

    class SoundService
    {
    private:
        const float background_music_volume = 20.f;

        sf::Music background_music;
        
        sf::Sound sound_effect;
        sf::Sound explosion_sound_effect;
        sf::Sound powerup_sound_effect;

        sf::SoundBuffer buffer_button_click;
        sf::SoundBuffer buffer_bullet_fire;
        sf::SoundBuffer buffer_explosion;
        sf::SoundBuffer buffer_powerup_enabled;
        sf::SoundBuffer buffer_powerup_disabled;

        void loadBackgroundMusicFromFile();
        void loadSoundFromFile();

    public:
        void initialize();

        void playSound(SoundType soundType);
        void playBackgroundMusic();
    };
}