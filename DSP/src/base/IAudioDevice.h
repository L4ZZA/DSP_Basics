#pragma once

#include <string>
#include "IAudioData.h"
/*
    This interface defines the main operation 
    associated to an AudioDevice object
*/
class IAudioDevice
{
public:
    virtual ~IAudioDevice() {}
    virtual IAudioData* CreateAudioFromFile(const std::string &filePath) = 0;
    virtual void ReleaseAudio(IAudioData *audioData) = 0;
};