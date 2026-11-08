#include <stdio.h>

int main()
{
    int c, d, state, prev;

    state = 0;
    prev = 0;

    while ((c = getchar()) != EOF)
    {
        if (state == 0)
        {
            if (c == '"')
            {
                putchar(c);
                state = 1;
            }
            else if (c == '\'')
            {
                putchar(c);
                state = 2;
            }
            else if (c == '/')
            {
                d = getchar();

                if (d == '*')
                {
                    putchar(' ');
                    state = 3;
                }
                else
                {
                    putchar(c);

                    if (d != EOF)
                        ungetc(d, stdin);
                }
            }
            else
                putchar(c);
        }
        else if (state == 1 || state == 2)
        {
            putchar(c);

            if (c == '\\')
            {
                d = getchar();

                if (d != EOF)
                    putchar(d);
            }
            else if ((state == 1 && c == '"') ||
                (state == 2 && c == '\''))
                state = 0;
        }
        else if (state == 3)
        {
            if (prev == '*' && c == '/')
            {
                state = 0;
                prev = 0;
            }
            else
                prev = (c == '*');
        }
    }

    return 0;
}