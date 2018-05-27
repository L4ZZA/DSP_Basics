#include "AudioObject.h"
#include "maths/Clamp.h"

AudioObject::AudioObject(const SampleInfo & info, IAudioData * data)
    : m_audioPos(0),
    m_audioLength(data->GetAudioLength()),
    m_sampleInfo(info),
    m_audioData(data)
{
}

bool AudioObject::GenerateSamples(float * stream, size_t streamLength)
{
    m_audioPos = m_audioData->GenerateSamples(stream, streamLength, m_audioPos, m_sampleInfo);

    if (m_audioPos == (size_t)-1)
    {
        m_audioPos = 0;
        return false;
    }
    return true;
}

void AudioObject::SetPos(double pos)
{
    pos = maths::func::Clamp(pos, 0.0, 1.0);

    m_audioPos = PosToAbsolutePos(pos);
}

size_t AudioObject::PosToAbsolutePos(double pos)
{
    return (size_t)(pos * m_audioLength);
}
