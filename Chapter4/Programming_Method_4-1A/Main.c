#include <stdio.h>

int strindex(char s[], char t[]) {
	int i, j, k;
	int found = -1;
	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			found = i;
	}
	return found;
}

int main(void)
{
	char s[] = "abcdedfabcde";
	char t[] = "abc";
	int index;

	index = strindex(s, t);
	if (index >= 0) {
		printf("Substring found at index: %d\n", index);
	} else {
		printf("Substring not found\n");
	}

	return 0;
}