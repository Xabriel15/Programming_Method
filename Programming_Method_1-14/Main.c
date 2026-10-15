#include <stdio.h>

main()
{
	int letter[150] = {0};
	int c;

	while ((c = getchar()) != EOF)
	{
		letter[c]++;
	}

	for (int i = 0; i < 150; i++)
	{
		if (letter[i] > 0) {
			if (i == ' ')
			{
				printf("Space: %2d \n", letter[i]);
			}
			else if (i == '\n')
			{
				printf("new Lines: %2d \n", letter[i]);
			}
			else if (i == '\t')
			{
				printf("Tabs: %2d \n", letter[i]);
			}

			else
			{
				printf("%C: %2d \n", i, letter[i]);
			}
		}
	}
}