#include <stdio.h>
#include <string.h>

/* Reverse a string in place */
void reverse(char s[])
{
    int i, j;
    char temp;

    for (i = 0, j = (int)strlen(s) - 1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

/* Convert an integer to a string with minimum field width */
void itoa(int n, char s[], int width)
{
    int i = 0;
    int sign;

    sign = n;

    do
    {
        s[i++] = (char)(n % 10 + '0');
    } while ((n /= 10) != 0);

    if (sign < 0)
    {
        s[i++] = '-';
    }

    /* Pad with zeros until the requested width is reached */
    while (i < width)
    {
        s[i++] = '0';
    }

    s[i] = '\0';

    reverse(s);
}

int main(void)
{
    int number;
    int width;
    char result[100];

    printf("Enter an integer: ");
    scanf("%d", &number);

    printf("Enter minimum field width: ");
    scanf("%d", &width);

    itoa(number, result, width);

    printf("Converted string: %s\n", result);

    return 0;
}