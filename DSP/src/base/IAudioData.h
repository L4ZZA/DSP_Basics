#pragma once
#include <cstddef>
#include "SampleInfo.h"

/*
    This interface specifies the basic 
*/
class IAudioData
{
public:
    virtual ~IAudioData() {}
    virtual size_t GenerateSamples(float *stream, size_t streamLength, size_t pos, const SampleInfo & info) = 0;
    virtual size_t GetAudioLength() = 0;
};