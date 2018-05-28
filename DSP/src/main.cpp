#include <iostream>
#include <SDL.h>

#include "sdl/SDLAudioDevice.h"
#include "sdl/SDLAudioContext.h"

#define FILE_PATH "res/gong-16-bit.wav"

int main(int argc, char** agrs)
{
    SDL_Init(SDL_INIT_AUDIO);

    IAudioDevice*  device  = new SDLAudioDevice();
    IAudioContext* context = new SDLAudioContext();

    
    IAudioData* data = device->CreateAudioFromFile(FILE_PATH);
    
    SampleInfo info;
    info.volume = 1.0;

    AudioObject sound(info, data);

    char in = 0;
    while (in != 'q')
    {
        std::cin >> in;
        switch (in) 
        {
        case 'a':
            context->PlayAudio(sound);
            break;
        case 's':
            context->PauseAudio(sound);
            break;
        case 'd':
            context->StopAudio(sound);
            break;
        default:
            break;
        }
    }

    device->ReleaseAudio(data);
    delete context;
    delete device;

    SDL_Quit();
    return 0;
}