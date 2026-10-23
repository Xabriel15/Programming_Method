#include <stdio.h>
#include <limits.h>
#define MAXLINE 1000

int htoi(s)
char s[];
{
	int i, n;
	int c;

	n = 0;

	for (i = 0; s[i] != '\0'; ++i) {
		c = s[i];

		if (c >= '0' && c <= '9')
			c = c - '0';
		else if (c >= 'a' && c <= 'f')
			c = c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
			c = c - 'A' + 10;
		else
			return -1;

		n = 16 * n + c;
	}

	return n;
}

int main()
{

	int htoi();
	printf("htoi('84ada') = %d\n", htoi("84ada"));
	printf("htoi('f') = %d\n", htoi("f"));
	printf("htoi('F0') = %d\n", htoi("F0"));
	printf("htoi('12fab') = %d\n", htoi("12fab"));

	return 0;
}