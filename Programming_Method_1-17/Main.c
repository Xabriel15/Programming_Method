#include <stdio.h>
main()
{
	int c = 0;
	char line[1000] = { 0 };
	int currentCharacters = 0;
	int limit = 80;
	
	
	while ((c = getchar()) != EOF)
	{
		line[currentCharacters] = c;
		currentCharacters++;

		if (c == '\n')
		{
			if (currentCharacters > limit)
			{
				printf("characters amount: %d\n", currentCharacters);
				for (int i = 0; i < currentCharacters; i++)
				{
					printf("%C", line[i]);
				}
			}
			currentCharacters = 0;
		}
	}
}