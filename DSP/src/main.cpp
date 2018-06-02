#include "easy_input.h"

#define ESC 27

int main()
{
    while (int input = getChar() != ESC);
    return 0;
}