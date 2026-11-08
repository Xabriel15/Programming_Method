#include <stdio.h>

void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (i = k = 0; s1[i] != '\0'; i++)
    {
        for (j = 0; s2[j] != '\0' && s1[i] != s2[j]; j++)
            ;

        if (s2[j] == '\0')
            s1[k++] = s1[i];
    }

    s1[k] = '\0';
}

int main()
{
    char s1[] = "hello world";
    char s2[] = "ole";

    squeeze(s1, s2);

    printf("%s\n", s1);

    return 0;
}