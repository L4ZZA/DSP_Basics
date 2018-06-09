#include <SFML/Audio.hpp>

#include "base/easy_input.h"

#define ESC 27

int main(void)
{
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("res/gong-16-bit.wav"))
        return -1;
    
    sf::Sound sound;
    sound.setBuffer(buffer);

    bool isPlaying = false;

    char input(0);
    while (input != ESC)
    {
        input = getChar();
        switch (input)
        {
        case 'p':
            if (!isPlaying)
                sound.play();
            else
                sound.pause();

            isPlaying = !isPlaying;
            break;
        default:
            break;
        }
    }

    return 0;
}