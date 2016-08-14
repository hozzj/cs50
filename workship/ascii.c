#include <stdio.h>

int main(void)
{
    for (char c = 'A'; c <= 'Z'; c += 1)
    {
        printf("%i is %c\n", (int) c, c);
    }
}