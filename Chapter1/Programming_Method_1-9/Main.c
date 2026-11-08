#include <stdio.h>

int main(void)
{
    int c;
    int prevc = 0;

    while ((c = getchar()) != EOF)
    {
        if (c != ' ' || prevc != ' ')
        {
            putchar(c);
        }

        prevc = c;
    }

    return 0;
}