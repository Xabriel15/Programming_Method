
#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa: convert integer n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;

    i = 0;

    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';

    reverse(s);
}
//  3-4
void itoaBig(int n, char s[])
{
    unsigned int magnitude;
    int i = 0;
    int negative = n < 0;

    if (negative)
        magnitude = 0u - (unsigned int)n;
    else
        magnitude = (unsigned int)n;

    do {
        s[i++] = magnitude % 10 + '0';
    } while ((magnitude /= 10) > 0);

    if (negative)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

//3-5
void itob(int n, char s[], int b)
{
    unsigned int magnitude;
    int i = 0;
    int negative = n < 0;
    char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (b < 2 || b > 36) {
        s[0] = '\0';
        return;
    }

    magnitude = negative ? 0u - (unsigned int)n : (unsigned int)n;

    do {
        s[i++] = digits[magnitude % b];
    } while ((magnitude /= b) > 0);

    if (negative)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}


int main(void)
{
    int n;
    char s[20];

    printf("Enter an integer: ");

    if (scanf_s("%d", &n) == 1) {
        itob(n, s, 16);
        printf("Converted string: %s\n", s);
    }

    return 0;
}
