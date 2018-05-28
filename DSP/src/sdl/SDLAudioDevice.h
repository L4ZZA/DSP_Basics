#pragma once
#include "../base/IAudioDevice.h"

class SDLAudioDevice : public IAudioDevice
{
public:
    virtual IAudioData* CreateAudioFromFile(const std::string &filePath);
    virtual void ReleaseAudio(IAudioData *audioData);
};
