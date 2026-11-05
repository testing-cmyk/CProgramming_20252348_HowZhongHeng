//exe 1 - 20~24
//exercise 20
#include <stdio.h>

#define TABSTOP 8

int main()
{
    int c;
    int pos = 0;
    int spaces;
    int i;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            spaces = TABSTOP - (pos % TABSTOP);

            for (i = 0; i < spaces; i++)
            {
                putchar(' ');
                ++pos;
            }
        }
        else
        {
            putchar(c);

            if (c == '\n')
                pos = 0;
            else
                ++pos;
        }
    }

    return 0;
}



//exercise 21

#include <stdio.h>

#define TABSTOP 8

int main()
{
    int c;
    int spaces = 0;
    int pos = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            ++spaces;
            ++pos;

            if (pos % TABSTOP == 0)
            {
                putchar('\t');
                spaces = 0;
            }
        }
        else
        {
            while (spaces > 0)
            {
                putchar(' ');
                --spaces;
            }

            putchar(c);

            if (c == '\n')
                pos = 0;
            else
                ++pos;
        }
    }

    return 0;
}

//exercise 23

#include <stdio.h>

int main()
{
    int c, prev;

    prev = getchar();

    while ((c = getchar()) != EOF)
    {
        if (prev == '/' && c == '*')
        {
            while ((prev = getchar()) != EOF)
            {
                c = getchar();

                if (prev == '*' && c == '/')
                    break;
            }

            prev = getchar();
        }
        else
        {
            putchar(prev);
            prev = c;
        }
    }

    return 0;
}



//exercise 24

#include <stdio.h>
 
int main()
{
int c;
 
int paren = 0;
int brace = 0;
int bracket = 0;
 
while ((c = getchar()) != EOF)
{
if (c == '(')
++paren;
else if (c == ')')
--paren;
 
else if (c == '{')
++brace;
else if (c == '}')
--brace;
 
else if (c == '[')
++bracket;
else if (c == ']')
--bracket;
}
 
if (paren == 0)
printf("Parentheses ok\n");
else
printf("Parentheses error\n");
 
if (brace == 0)
printf("Braces ok\n");
else
printf("Braces error\n");
 
if (bracket == 0)
printf("Brackets ok\n");
else
printf("Brackets error\n");
 
return 0;
}