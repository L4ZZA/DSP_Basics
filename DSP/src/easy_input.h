#pragma once
#include <cstdio>
#include <conio.h>

#define RELEASED 0
// WARNING: Update the prefix with the first value shown,
// if when pressing arrow keys it prints 2 lines
#define ARROW_PREFIX -32

/*
* Reads single key pressed with optional echoing.
* Param: pass true if you want to see the value of the key pressed
* Returns: the char equivalent of the key pressed
*/
inline char getChar(bool show = false)
{
    char ch = _getch();

    // overridig arrow keys prefix if found
    if (ch == ARROW_PREFIX)
    {
        ch = _getch();
    }

    // prints the int value of the key and the char itself
    if (show && ch != RELEASED)
    {
        printf("%d - %c\n", ch, ch);
    }

    return ch;
}