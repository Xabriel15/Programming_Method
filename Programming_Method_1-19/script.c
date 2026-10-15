#include <stdio.h>


int toFahrenheit(int);
int toCelsius(int);
void reverse(char[], int length);

//main()
//{
//	int fahr, celsius;
//	int lower, upper, step;
//
//	lower = 0;
//	upper = 300;
//	step = 20;
//
//	//fahr = lower;
//	//while (fahr <= upper)
//	//{
//	//	celsius = 5 * (fahr - 32) / 9;
//	//	printf("%d\t%d\n", fahr, celsius);
//	//	fahr = fahr + step;
//	//}
//
//	celsius = upper;
//	printf("celsius fahr\n");
//	while (celsius >= lower)
//	{
//		fahr = 9 * celsius / 5 + 32;
//		printf("%d\t%d\n", celsius, fahr);
//		celsius = celsius - step;
//	}
//
//	
//
//
//}
main()
{
	//int c;
	//int nl;
	//int	blank;
	//int	tabs;

	//nl = 0;
	//blank = 0;
	//tabs = 0;

	//	while ((c = getchar()) != EOF)
	//	{ 
	//		if (c == '\n') ++nl;
	//		else if (c == '\t') ++tabs;
	//		else if (c == ' ') ++blank;
	//	}
	//	printf("New Lines: %d Tabs: %d Blanks: %d\n", nl,  tabs,  blank);


		//int c;
		//int prevc = 0;

		//prevc = getchar();

		//while ((prevc = getchar()) != EOF)
		//{	
		//	c = getchar();

		//	if (prevc == ' ' && prevc == c)
		//	{
		//		continue;
		//	}
		//		putchar(prevc);
		//		prevc = c;
		//}
	int c = 0;
	int counter = 0;
	char charArray[1000] = {0};

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
			counter = 0;
		}

	}
	return 0;
}

//1-19 Function
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
		j--;
	}
}