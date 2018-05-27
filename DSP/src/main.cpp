#include <stdio.h>
#include <SDL.h>

int main(int argc, char** agrs)
{
    SDL_Init(SDL_INIT_AUDIO);

    printf("Lets start with DSP");

    SDL_Quit();
    return 0;
}