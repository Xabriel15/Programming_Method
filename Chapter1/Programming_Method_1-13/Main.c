#include <stdio.h>

main()
{
    int c;
    int length = 0;
    int wordCount = 0;
    int wordLength[20] = { 0 };

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            wordCount++;
            wordLength[wordCount] = length;
            length = 0;
        }
        else
        {
            length++;
        }
    }

    // Count the final word if the input didn't end with whitespace

    wordLength[length]++;

    for (int i = 1; i <= wordCount; i++)
    {
        printf("%2d: ", i);

        for (int j = 0; j < wordLength[i]; j++)
        {
            putchar('*');
        }

        putchar('\n');
    }
    return 0;
}