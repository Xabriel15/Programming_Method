#include <stdio.h>

#define MAXSTACK 10000

int main()
{
    int c, d, state, prev;
    int top, errors;
    char stack[MAXSTACK];

    state = 0;
    prev = 0;
    top = -1;
    errors = 0;

    while ((c = getchar()) != EOF)
    {
        if (state == 0)
        {
            if (c == '"')
                state = 1;
            else if (c == '\'')
                state = 2;
            else if (c == '/')
            {
                d = getchar();

                if (d == '*')
                {
                    state = 3;
                    prev = 0;
                }
                else if (d != EOF)
                    ungetc(d, stdin);
            }
            else if (c == '(' || c == '[' || c == '{')
            {
                if (top < MAXSTACK - 1)
                    stack[++top] = c;
                else
                {
                    printf("Stack overflow\n");
                    errors++;
                }
            }
            else if (c == ')' || c == ']' || c == '}')
            {
                if (top == -1)
                {
                    printf("Unmatched closing character: %c\n", c);
                    errors++;
                }
                else
                {
                    char expected;

                    if (c == ')')
                        expected = '(';
                    else if (c == ']')
                        expected = '[';
                    else
                        expected = '{';

                    if (stack[top] != expected)
                    {
                        printf("Mismatched closing character: %c\n", c);
                        errors++;
                    }

                    top--;
                }
            }
        }
        else if (state == 1 || state == 2)
        {
            if (c == '\\')
            {
                d = getchar();

                if (d == EOF)
                    break;
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

    if (state == 1)
    {
        printf("Unterminated string\n");
        errors++;
    }
    else if (state == 2)
    {
        printf("Unterminated character constant\n");
        errors++;
    }
    else if (state == 3)
    {
        printf("Unterminated comment\n");
        errors++;
    }

    while (top >= 0)
    {
        printf("Unmatched opening character: %c\n", stack[top--]);
        errors++;
    }

    if (errors == 0)
        printf("No basic syntax errors found\n");
    else
        printf("Total errors: %d\n", errors);

    return 0;
}