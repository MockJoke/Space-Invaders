#include "../../header/Sound/SoundService.h"
#include "../../Header/Global/Config.h"

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
    }

    void SoundService::playSound(SoundType soundType)
    {
        switch (soundType)
        {
        case SoundType::BUTTON_CLICK:
            sound_effect.setBuffer(buffer_button_click);
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
