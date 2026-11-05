// exercise 5-7
#include <stdio.h>
#include <string.h>

#define MAXLINES 100
#define MAXLEN 1000

/* Read one line */
int getline_array(char *line, int max)
{
    int c;
    int i = 0;

    while (i < max - 1 &&
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

/*
 * Exercise 5-7:
 * Read lines into an array supplied by main.
 */
int readlines(char *lineptr[], int maxlines,
              char storage[], int maxstorage)
{
    int len;
    int nlines = 0;
    int storage_used = 0;

    while (nlines < maxlines)
    {
        len = getline_array(
            storage + storage_used,
            maxstorage - storage_used
        );

        if (len == 0)
            break;

        if (storage_used + len >= maxstorage)
            break;

        lineptr[nlines++] = storage + storage_used;
        storage_used += len;
    }

    return nlines;
}

/* Print stored lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s", lineptr[i]);
}

/* Main function */
int main(void)
{
    char *lineptr[MAXLINES];
    char storage[MAXLINES * MAXLEN];

    int nlines;

    printf("Readline Using Array - Exercise 5-7\n");
    printf("-----------------------------------\n");

    printf("Enter lines of text.\n");
    printf("Press Ctrl+Z followed by Enter to finish.\n\n");

    nlines = readlines(
        lineptr,
        MAXLINES,
        storage,
        sizeof(storage)
    );

    printf("\nStored lines:\n");

    writelines(lineptr, nlines);

    return 0;
}
