#pragma once

/*
    This interface
*/
class IAudioContext
{
public:
    virtual ~IAudioContext() {}
    virtual void PlayAudio(AudioObject &ao) = 0;
    virtual void PauseAudio(AudioObject &ao) = 0;
    virtual void StopAudio(AudioObject &ao) = 0;
};