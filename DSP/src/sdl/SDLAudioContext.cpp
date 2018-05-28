#include "SDLAudioContext.h"

#include <iostream>
#include "../maths/Clamp.h"

static void AudioCallback(void *userData, Uint8 *streamIn, int length)
{
    SDLAudioContext *context = (SDLAudioContext*)userData;
    context->GenerateSamples(streamIn, length);
}

SDLAudioContext::SDLAudioContext()
{
    SDL_AudioSpec spec;

    //TODO: don't hardcode these values.
    SDL_zero(spec);
    spec.freq = 44100;
    spec.format = AUDIO_S16SYS;
    spec.channels = 2;
    spec.samples = 2048;
    spec.callback = AudioCallback;
    spec.userdata = this;

    //TODO: handle different specs
    m_device = SDL_OpenAudioDevice(nullptr, 0, &spec, nullptr, 0);
    if (m_device == 0)
    {
        throw SDL_GetError();
    }

    SDL_PauseAudioDevice(m_device, 0);
}

SDLAudioContext::~SDLAudioContext()
{
    SDL_CloseAudioDevice(m_device);
}

void SDLAudioContext::PlayAudio(AudioObject & ao)
{
    SDL_LockAudioDevice(m_device);

    // to prevent duplicates
    removeAudio(ao);
    m_playingAudio.push_back(&ao);

    SDL_UnlockAudioDevice(m_device);
}

void SDLAudioContext::PauseAudio(AudioObject & ao)
{
    SDL_LockAudioDevice(m_device);

    // to prevent duplicates
    removeAudio(ao);

    SDL_UnlockAudioDevice(m_device);
}

void SDLAudioContext::StopAudio(AudioObject & ao)
{
    SDL_LockAudioDevice(m_device);

    // to prevent duplicates
    if (removeAudio(ao))
    {
        ao.SetPos(0.0);
    }

    SDL_UnlockAudioDevice(m_device);
}

void SDLAudioContext::GenerateSamples(Uint8 * streamIn, int streamInLen)
{
    size_t streamLen = (size_t)(streamInLen / 2);

    m_stream.reserve(streamLen);

    // clearing the stream
    float *floatStream = *(float**)(&m_stream);
    for (size_t i = 0; i < streamLen; i++)
    {
        floatStream[i] = 0.0f;
    }

    // Samples generation
    std::vector<AudioObject*>::iterator it  = m_playingAudio.begin();
    std::vector<AudioObject*>::iterator end = m_playingAudio.end();
    for (; it != end; ++it)
    {
        // trying to generate sample
        if (!(*it)->GenerateSamples(floatStream, streamLen))
        {
            //remove it if fails
            removeAudio(*(*it));
        }
    }


    Sint16 *stream = (Sint16*)streamIn;
    for (size_t i = 0; i < streamLen; i++)
    {
        float val = floatStream[i];

        // limiting the value to the range [-1:1]
        val = maths::func::Clamp(val, -1.0f, 1.0f);

        stream[i] = (Sint16)(val * 32767);
    }
}

bool SDLAudioContext::removeAudio(AudioObject & ao)
{
    std::vector<AudioObject*>::iterator it = m_playingAudio.begin();
    std::vector<AudioObject*>::iterator end = m_playingAudio.end();

    for (; it != end; ++it)
    {
        if (*it == &ao)
        {
            m_playingAudio.erase(it);
            return true;
        }
    }
    return false;
}
