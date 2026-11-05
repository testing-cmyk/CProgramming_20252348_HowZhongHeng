//ex 1 - 17~19
//exercise 17
#include <stdio.h>

#define MAXLINE 1000

int mgetline(char line[], int maxline);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = mgetline(line, MAXLINE)) > 0)
    {
        if (len > 80)
            printf("%s", line);
    }

    return 0;
}

int mgetline(char line[], int maxline)
{
    int c, i;

    for (i = 0; i < maxline - 1 &&
         (c = getchar()) != EOF &&
         c != '\n'; ++i)
        line[i] = c;

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}

//exercise 18




#include <stdio.h>

#define MAXLINE 1000

int mgetline(char line[], int maxline);

int main()
{
    int len, i;
    char line[MAXLINE];

    while ((len = mgetline(line, MAXLINE)) > 0)
    {
        i = len - 1;

        if (line[i] == '\n')
            --i;

        while (i >= 0 &&
               (line[i] == ' ' || line[i] == '\t'))
            --i;

        if (i >= 0)
        {
            line[i + 1] = '\n';
            line[i + 2] = '\0';
            printf("%s", line);
        }
    }

    return 0;
}

int mgetline(char line[], int maxline)
{
    int c, i;

    for (i = 0; i < maxline - 1 &&
         (c = getchar()) != EOF &&
         c != '\n'; ++i)
        line[i] = c;

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}


//exercise 19

#include <stdio.h>

#define MAXLINE 1000

int mgetline(char line[], int maxline);
void reverse(char s[]);

int main(){
    char line[MAXLINE];

    while (mgetline(line, MAXLINE) > 0)
    {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}

int mgetline(char line[], int maxline)
{
    int c, i;

    for (i = 0; i < maxline - 1 &&
         (c = getchar()) != EOF &&
         c != '\n'; ++i)
        line[i] = c;

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}

void reverse(char s[])
{
    int i, j;
    char temp;

    for (j = 0; s[j] != '\0'; ++j)
        ;

    if (s[j - 1] == '\n')
        --j;

    for (i = 0, --j; i < j; ++i, --j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}