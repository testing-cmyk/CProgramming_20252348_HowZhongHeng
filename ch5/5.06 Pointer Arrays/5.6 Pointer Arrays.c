// exercise 5-6
#include <stdio.h>

#define MAXLINES 100
#define MAXLEN 1000

/* Read a line into an array */
int getline_array(char line[], int maxline)
{
    int c;
    int i = 0;

    while (i < maxline - 1 &&
           (c = getchar()) != EOF &&
           c != '\n')
    {
        line[i++] = (char)c;
    }

    if (c == '\n')
        line[i++] = '\n';

    line[i] = '\0';

    return i;
}

/* Read multiple lines using a two-dimensional array */
int readlines(char lineptr[][MAXLEN], int maxlines)
{
    int len;
    int nlines = 0;

    while (nlines < maxlines &&
           (len = getline_array(lineptr[nlines], MAXLEN)) > 0)
    {
        nlines++;
    }

    return nlines;
}

/* Print all stored lines */
void writelines(char lineptr[][MAXLEN], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s", lineptr[i]);
}

/* Main program */
int main(void)
{
    char lineptr[MAXLINES][MAXLEN];
    int nlines;

    printf("Enter lines of text.\n");
    printf("Press Ctrl+Z followed by Enter to finish.\n\n");

    nlines = readlines(lineptr, MAXLINES);

    printf("\nStored lines:\n");
    writelines(lineptr, nlines);

    return 0;
}
