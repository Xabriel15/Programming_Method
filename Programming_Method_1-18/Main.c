#include <stdio.h>

main()
{
	int c = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\t' || c == ' ' || c == '\n')
		{
			//printf("\n");
		}
		else
		{
			printf("%C", c);
		}
	}
	return 0;
}