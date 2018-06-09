#pragma once

#include <SFML/Audio.hpp>

#include "../base/IAudioDevice.h"
#include "../base/IAudioData.h"

class SFMLAudioData : public IAudioData
{
private:

public:
    SFMLAudioData();
    ~SFMLAudioData();
    virtual size_t GenerateSamples(float *stream, size_t streamLength, size_t pos, const SampleInfo & info) = 0;
    virtual size_t GetAudioLength() = 0;

private:

};

SFMLAudioData::SFMLAudioData()
{
}

SFMLAudioData::~SFMLAudioData()
{
}