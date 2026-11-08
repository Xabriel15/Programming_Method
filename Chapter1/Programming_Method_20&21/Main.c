#include <stdio.h>

#define TAB_WIDTH 8

void detab(void);
void entab(void);
void flush_spaces(int* spaces, int* column);

int main(void)
{
    detab();
    return 0;
}

void detab(void)
{
    int c;
    int column = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            int spaces = TAB_WIDTH - column % TAB_WIDTH;

            for (int i = 0; i < spaces; i++)
                putchar(' ');

            column += spaces;
        }
        else if (c == '\n')
        {
            putchar(c);
            column = 0;
        }
        else
        {
            putchar(c);
            column++;
        }
    }
}

void flush_spaces(int* spaces, int* column)
{
    while (*spaces > 0)
    {
        int to_tab = TAB_WIDTH - *column % TAB_WIDTH;

        if (to_tab <= *spaces)
        {
            putchar('\t');
            *column += to_tab;
            *spaces -= to_tab;
        }
        else
        {
            putchar(' ');
            (*column)++;
            (*spaces)--;
        }
    }
}

void entab(void)
{
    int c;
    int column = 0;
    int spaces = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            spaces++;
            continue;
        }

        flush_spaces(&spaces, &column);

        if (c == '\n')
        {
            putchar(c);
            column = 0;
        }
        else if (c == '\t')
        {
            putchar(c);
            column += TAB_WIDTH - column % TAB_WIDTH;
        }
        else
        {
            putchar(c);
            column++;
        }
    }

    flush_spaces(&spaces, &column);
}