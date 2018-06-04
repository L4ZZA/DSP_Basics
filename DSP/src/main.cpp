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

    char input(0);
    while (input != ESC)
    {
        input = getChar();
        if (input == 'p')
        {
            sound.play();
        }
    }

    return 0;
}