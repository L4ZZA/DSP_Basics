#include "SDLWavAudioData.h"

#define INT16_MAX_VALUE 32767.0f

SDLWavAudioData::SDLWavAudioData(const std::string &fileName, bool streamFromFile)
{
    // TODO: handle streamFromFile

    SDL_AudioSpec wavSpec;
    Uint8 *wavStart;
    Uint32 wavLength;

    const char *cFileName = fileName.c_str();

    if (SDL_LoadWAV(cFileName, &wavSpec, &wavStart, &wavLength) == nullptr)
    {
        fprintf(stderr, "Could not open %s: %s\n", fileName, SDL_GetError());
        throw SDL_GetError();
    }

    m_pos = wavStart;
    m_start = wavStart;
    m_length = wavLength;
}

SDLWavAudioData::~SDLWavAudioData()
{
    SDL_FreeWAV(m_start);
}

size_t SDLWavAudioData::GenerateSamples(float * stream, size_t streamLength, size_t pos, const SampleInfo & info)
{
    // TODO: handle pos

    if (m_length == 0)
    {
        return (size_t)-1;
    }

    Uint32 length = (Uint32)streamLength;
    length = length > m_length ? m_length : length;

    // TODO: make this more general
    Sint16 *samples = (Sint16*)m_pos;
    float factor = (float)info.volume / INT16_MAX_VALUE;
    for (Uint32 i = 0; i < length; i++)
    {
        stream[i] = (*samples) * factor;
        samples++;
    }

    m_pos = (Uint8*)samples;
    // since sample is 16bits so 2 bytes
    // every iteration we use 2 samples
    m_length -= length * 2;

    return m_length;
}

size_t SDLWavAudioData::GetAudioLength()
{
    return m_length;
}
