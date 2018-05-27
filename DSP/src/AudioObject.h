#pragma once

#include "IAudioData.h"
#include "SampleInfo.h"

/*
    it's a wrapper on the IAudioData interface that helps
    operate on the data and on the audio info (volume, pitch, etc.)
*/
class AudioObject
{
private:
    size_t      m_audioPos;
    size_t      m_audioLength;
    SampleInfo  m_sampleInfo;
    IAudioData *m_audioData;

public:
    AudioObject(const SampleInfo &info, IAudioData *data);

    /*
    Generate samples.
    Params:
        - stream: the audio stream (it's float cause is more flexible)
        - streamLength: uint length of the stream
    Returns:
        - true: if there's still more audio to generate
        - false: if it's at the end of the file
    */
    bool GenerateSamples(float *stream, size_t streamLength);

    /*
    Sets the playback position.
    Param:
        - Normalized position (between 0 and 1) of the sample in the audio
    */
    void SetPos(double pos);

private:
    /*
    Transforms the normalized position (between 0 and 1) to the real position
    of the file based on the audio lenght.
    Param:
        - Normalized position (between 0 and 1) of the sample in the audio
    Return:
        - The acutal position between 0 and the audio length
    */
    size_t PosToAbsolutePos(double pos);
};