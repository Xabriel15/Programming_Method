#include <stdio.h>

void reverse(char[], int length);

main()
{
	int c = 0;
	int counter = 0;
	char charArray[1000] = { 0 };

	while ((c = getchar()) != EOF)
	{
		charArray[counter] = c;
		counter++;

		if (c == '\n')
		{
			reverse(charArray, counter);
			for (int i = 0; i < counter; i++)
			{
				printf("%C", charArray[i]);
			}
			printf("\n");
			counter = 0;
		}

	}
	return 0;
}
void reverse(char _s[], int _length)
{
	int i, j;
	char _temp;
	j = _length - 1;
	for (i = 0, j = _length - 1; i < j; i++, j--)
	{
		_temp = _s[i];
		_s[i] = _s[j];
		_s[j] = _temp;
	}
}