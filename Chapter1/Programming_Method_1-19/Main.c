#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int limit);
void reverse(char s[]);

int main()
{
    char line[MAXLINE];

    while (get_line(line, MAXLINE) > 0)
    {
        reverse(line);
        printf("%s\n", line);
    }

    return 0;
}

int get_line(char s[], int limit)
{
    int c, i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';

    return i;
}

void reverse(char s[])
{
    int i, j;
    char temp;

    for (i = 0; s[i] != '\0' && s[i] != '\n'; i++)
        ;

    j = i - 1;

    for (i = 0; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}