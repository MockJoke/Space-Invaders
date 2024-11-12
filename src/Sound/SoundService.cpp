#include "../../include/Sound/SoundService.h"
#include "../../include/Global/Config.h"

namespace Sound
{
    void SoundService::initialize()
    {
        loadBackgroundMusicFromFile();
        loadSoundFromFile();
    }

    void SoundService::loadBackgroundMusicFromFile()
    {
        if (!background_music.openFromFile(Global::Config::background_music_path))
        {
            printf("Error loading background music file");
        }
    }

    void SoundService::loadSoundFromFile()
    {
        if (!buffer_button_click.loadFromFile(Global::Config::button_click_sound_path))
        {
            printf("Error loading background music file");
        }

        if (!buffer_bullet_fire.loadFromFile(Global::Config::bullet_fire_sound_path))
        {
            printf("Error loading bullet fire sound file");
        }

        if (!buffer_powerup_enabled.loadFromFile(Global::Config::powerup_enabled_sound_path))
        {
            printf("Error loading powerup enabled sound file");
        }

        if (!buffer_powerup_disabled.loadFromFile(Global::Config::powerup_disabled_sound_path))
        {
            printf("Error loading powerup disabled sound file");
        }
    }

    void SoundService::playSound(SoundType soundType)
    {
        switch (soundType)
        {
        case SoundType::BUTTON_CLICK:
            sound_effect.setBuffer(buffer_button_click);
            sound_effect.play();
            break;

        case SoundType::BULLET_FIRE:
            sound_effect.setBuffer(buffer_bullet_fire);
            sound_effect.play();
            break;

        case SoundType::EXPLOSION:
            explosion_sound_effect.setBuffer(buffer_explosion);
            explosion_sound_effect.play();
            break;

        case SoundType::POWERUP_ENABLED:
            powerup_sound_effect.setBuffer(buffer_powerup_enabled);
            powerup_sound_effect.play();
            break;

        case SoundType::POWERUP_DISABLED:
            powerup_sound_effect.setBuffer(buffer_powerup_disabled);
            powerup_sound_effect.play();
            break;
            
        default:
            printf("Invalid sound type");
            return;
        }

        sound_effect.play();
    }

    void SoundService::playBackgroundMusic()
    {
        background_music.setLoop(true);
        background_music.setVolume(background_music_volume);
        background_music.play();
    }
}
