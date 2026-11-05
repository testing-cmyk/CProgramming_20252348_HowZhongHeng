// exercise 5-2
#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int c);
int getint(int *pn);

char buf[BUFSIZE];
int bufp = 0;

/* Read a character from input */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* Push a character back into input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("Error: buffer full\n");
    else
        buf[bufp++] = c;
}

/* Read the next integer from input */
int getint(int *pn)
{
    int c;
    int sign;

    /* Skip whitespace */
    while (isspace(c = getch()))
        ;

    /* Check for EOF */
    if (c == EOF)
        return EOF;

    /* Check for a sign */
    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
    {
        int next = getch();

        if (!isdigit(next))
        {
            if (next != EOF)
                ungetch(next);

            ungetch(c);
            return 0;
        }

        c = next;
    }

    /* First character must be a digit */
    if (!isdigit(c))
    {
        ungetch(c);
        return 0;
    }

    /* Read integer digits */
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;

    /* Push back the first non-digit character */
    if (c != EOF)
        ungetch(c);

    return c;
}

/* Main program */
int main(void)
{
    int n;
    int result;

    printf("Integer Reader (getint)\n");
    printf("-----------------------\n");
    printf("Enter integers separated by spaces.\n");
    printf("Press Ctrl+Z followed by Enter to finish.\n\n");

    while ((result = getint(&n)) != EOF)
    {
        if (result != 0)
            printf("Integer: %d\n", n);
        else
            printf("Input is not an integer.\n");
    }

    return 0;
}
