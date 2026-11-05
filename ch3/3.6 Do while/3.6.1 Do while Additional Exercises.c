// ex 3 - 4~6
#include <stdio.h>
#include <limits.h>

void reverse(char s[])
{
    int i, j;
    char temp;

    for (i = 0, j = 0; s[j] != '\0'; j++)
        ;

    j--;

    while (i < j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        i++;
        j--;
    }
}

// Exercise 3-4:
void itoa(int n, char s[])
{
    int i = 0;
    unsigned int value;

    if (n < 0)
    {
        s[i++] = '-';
        value = 0u - (unsigned int)n;
    }
    else
    {
        value = (unsigned int)n;
    }

    do
    {
        s[i++] = (char)(value % 10 + '0');
        value /= 10;
    } while (value > 0);

    if (s[0] == '-')
    {
        reverse(s + 1);
    }
    else
    {
        reverse(s);
    }

    s[i] = '\0';
}

// Exercise 3-5:
void itob(int n, char s[], int b)
{
    int i = 0;
    unsigned int value;
    char digits[] = "0123456789ABCDEF";

    if (b < 2 || b > 16)
    {
        s[0] = '\0';
        return;
    }

    if (n < 0)
    {
        s[i++] = '-';
        value = 0u - (unsigned int)n;
    }
    else
    {
        value = (unsigned int)n;
    }

    do
    {
        s[i++] = digits[value % b];
        value /= b;
    } while (value > 0);

    if (s[0] == '-')
    {
        reverse(s + 1);
    }
    else
    {
        reverse(s);
    }

    s[i] = '\0';
}

//Exercise 3-6:
void itoa_width(int n, char s[], int width)
{
    int i = 0;
    int j;
    unsigned int value;
    char temp[100];

    if (n < 0)
    {
        temp[i++] = '-';
        value = 0u - (unsigned int)n;
    }
    else
    {
        value = (unsigned int)n;
    }

    do
    {
        temp[i++] = (char)(value % 10 + '0');
        value /= 10;
    } while (value > 0);

    if (temp[0] == '-')
    {
        reverse(temp + 1);
    }
    else
    {
        reverse(temp);
    }

    temp[i] = '\0';

    j = width - i;

    if (j < 0)
        j = 0;
    int k = 0;

    while (k < j)
    {
        s[k++] = ' ';
    }

    for (int m = 0; m < i; m++)
    {
        s[k++] = temp[m];
    }

    s[k] = '\0';
}

int main(void)
{
    char result[100];

    printf("Exercise 3-4: itoa()\n");
    itoa(INT_MIN, result);
    printf("INT_MIN: %s\n", result);
    itoa(-12345, result);
    printf("Number: %s\n\n", result);

    printf("Exercise 3-5: itob()\n");
    itob(255, result, 2);
    printf("Binary: %s\n", result);
    itob(255, result, 8);
    printf("Octal: %s\n", result);
    itob(255, result, 10);
    printf("Decimal: %s\n", result);
    itob(255, result, 16);
    printf("Hexadecimal: %s\n\n", result);

    printf("Exercise 3-6: itoa_width()\n");
    itoa_width(123, result, 6);
    printf("Number: |%s|\n", result);
    itoa_width(-45, result, 7);
    printf("Number: |%s|\n", result);
    itoa_width(123456, result, 3);
    printf("Number: |%s|\n", result);
    return 0;
}