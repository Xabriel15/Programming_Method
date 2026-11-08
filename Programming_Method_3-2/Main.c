#include <stdio.h>
#define MAXLINE 1000

void escape(char s[], char t[]);
void unescape(char s[], char t[]);
int main()
{
	int c;
	int i = 0;
	char stringInput[MAXLINE];
	char stringOutput[MAXLINE];

	while ((c = getchar()) != EOF)
	{
		stringInput[i] = c;
		i++;
	}
	stringInput[i] = '\0';

	unescape(stringOutput, stringInput);
	
	printf("%s", stringOutput);
}

void escape(char s[], char t[])
{
	int i, j;
	i = j = 0;
	while (t[i] != '\0')
	{
		switch (t[i])
		{
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n';
			break;
		case '\t':
			s[j++] = '\\';
			s[j++] = 't';
			break;
		default:
			s[j++] = t[i];
			break;
		}
		i++;
	}
	s[j] = '\0';
}

void unescape(char s[], char t[])
{
	int i, j;
	i = j = 0;
	while (t[i] != '\0')
	{
		if (t[i] == '\\')
		{
			switch (t[i+1])
			{
			case 'n':
				s[j++] = '\n';
				break;
			case 't':
				s[j++] = '\t';
				break;
			default:
				break;
			}
			i++; // Skip the next character since it's part of the escape sequence
		}
		else
		{
			s[j++] = t[i];
		}
		i++;
	}
	s[j] = '\0';
}