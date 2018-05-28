#pragma once

#include <SDL.h>
#include <vector>

#include "../base/IAudioContext.h"
#include "../base/AudioObject.h"

class SDLAudioContext : public IAudioContext
{
private:
    SDL_AudioDeviceID m_device;
    std::vector<float> m_stream;
    std::vector<AudioObject*> m_playingAudio;

public:
    SDLAudioContext();
    SDLAudioContext(SDLAudioContext &other) { (void)other; }
    virtual ~SDLAudioContext();

    virtual void PlayAudio(AudioObject &ao);
    virtual void PauseAudio(AudioObject &ao);
    virtual void StopAudio(AudioObject &ao);

    void GenerateSamples(Uint8 *streamIn, int streamInLen);

private:
    bool removeAudio(AudioObject &ao);
    void operator=(const SDLAudioContext &other) { (void)other; }
};