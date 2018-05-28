#pragma once
#include "../base/IAudioData.h"
#include "../base/SampleInfo.h"

#include <SDL.h>
#include <string>

class SDLWavAudioData : public IAudioData
{
private:
    Uint8 *m_pos;
    Uint8 *m_start;
    Uint32 m_length;

public:
    SDLWavAudioData(const std::string &fileName, bool streamFromFile);
    SDLWavAudioData(SDLWavAudioData &other) { (void)other; }
    virtual ~SDLWavAudioData();

    virtual size_t GenerateSamples(float *stream, size_t streamLength, size_t pos, const SampleInfo &info);
    virtual size_t GetAudioLength();

private:
    void operator=(const SDLWavAudioData &other) { (void)other; }
};

