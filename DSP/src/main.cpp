#include "helpers/io/easy_input.h"

#define ESC 27

int main()
{
    while (int input = getChar(true) != ESC);
    return 0;
}