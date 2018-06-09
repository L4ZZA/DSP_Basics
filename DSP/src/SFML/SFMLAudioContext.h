#pragma once

#include <vector>
#include <SFML/Audio.hpp>

#include "../base/IAudioContext.h"
#include "../base/AudioObject.h"

class SFMLAudioContext : public IAudioContext
{
private:
    unsigned int m_device;
    std::vector<float> m_stream;
    std::vector<AudioObject*> m_playingAudio;

public:
    SFMLAudioContext();
    ~SFMLAudioContext();
    virtual void PlayAudio(AudioObject &ao);
    virtual void PauseAudio(AudioObject &ao);
    virtual void StopAudio(AudioObject &ao);
};

