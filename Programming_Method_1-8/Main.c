#include <stdio.h>

main()
{
	int c;
	int nl;
	int blank;
	int tabs;

	nl = 0;
	blank = 0;
	tabs = 0;

	while ((c = getchar()) != EOF)
	{ 
		if (c == '\n') ++nl;
		else if (c == '\t') ++tabs;
		else if (c == ' ') ++blank;
	}
	printf("New Lines: %d Tabs: %d Blanks: %d\n", nl,  tabs,  blank);
}