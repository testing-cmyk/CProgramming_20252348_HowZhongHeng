// reminder to use GIThub and back them up!
/* we've got exercises from 

1 - 1~2
// ex 1-1, 1-2

#include <stdio.h>

main() {
	printf("hello world!\n");
	return;

}

1 - 3~4
#include <stdio.h>
main() {
	int fahr, celsius;
	int lower, upper, step;

	lower = 0; // lower limit of temperature table
	upper = 300; // upper limit
	step = 20; // step size (kas kiek kyla)

	fahr = lower;

	printf("char\t\t-> %d\n", sizeof(char));
	printf("short\t\t-> %d\n", sizeof(short));
	printf("int\t\t-> %d\n", sizeof(int));
	printf("long\t\t-> %d\n", sizeof(long));
	printf("long long\t\t-> %d\n", sizeof(long long));
	printf("float\t\t-> %d\n", sizeof(float));
	printf("double\t\t-> %d\n", sizeof(double));
	printf("long double\t\t-> %d\n", sizeof(long double));

	printf("Fahrenheit_to_Celsius_Table\n");

	while (fahr <= upper) {
		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t\%d\n", fahr, celsius);
		fahr = fahr + step;

	}

	printf("Celsius_To_Fahrenheit_Table\n");

	celsius = lower;

	while (celsius <= upper) {
		fahr = (9 * celsius) / 5 + 32;
		printf("%d\t\t%d\n", celsius, fahr);
		celsius = celsius + step;
	}
	return 0;
}

1 - 5
#include <stdio.h>
main() {
	int fahr, celsius;
	int lower, upper, step;

	lower = 0; // lower limit of temperature table
	upper = 300; // upper limit
	step = 20; // step size (kas kiek kyla)

	fahr = upper;

	printf("char\t\t-> %d\n", sizeof(char));
	printf("short\t\t-> %d\n", sizeof(short));
	printf("int\t\t-> %d\n", sizeof(int));
	printf("long\t\t-> %d\n", sizeof(long));
	printf("long long\t\t-> %d\n", sizeof(long long));
	printf("float\t\t-> %d\n", sizeof(float));
	printf("double\t\t-> %d\n", sizeof(double));
	printf("long double\t\t-> %d\n", sizeof(long double));

	printf("Fahrenheit_to_Celsius_Table\n");

	while (fahr >= lower) {
		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t\%d\n", fahr, celsius);
		fahr = fahr - step;

	}

	printf("Celsius_To_Fahrenheit_Table\n");

	celsius = upper;

	while (celsius >= lower) {
		fahr = (9 * celsius) / 5 + 32;
		printf("%d\t\t%d\n", celsius, fahr);
		celsius = celsius - step;
	}
	return 0;
}

#include <stdio.h>

#define IN 1 // inside a word
#define OUT 0 // outside

// count lines, words, characters in input
main() {
	int c, nl, nw, nc, state;
	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n') ++ nl;
		if (c == ' ' || c == '\n' || c == '\t') state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}

1 - 11 ~ 12
#include <stdio.h>
#define IN 1
#define OUT 0

int main() {
    int c, state;

    state = OUT;

    while ((c = getchar()) != EOF) {

        if (c == ' ' || c == '\n' || c == '\t') {

            if (state == IN) {
                putchar('\n');
                state = OUT;
            }
        }
        else {
            putchar(c);
            state = IN;
        }
    }
    return 0;
}

1 - 13 ~ 14
#include <stdio.h>
int main() {
    int c;
    int length = 0;
    int i;

    while ((c = getchar()) != '\n') {
        if (c == ' ' || c == '\t') {
            for (i = 0; i < length; i++)
                printf("*");

            printf("\n");
            length = 0;
        }
        else {
            ++length;
        }
    }

    if (length > 0) {
        for (i = 0; i < length; i++)
            printf("*");

        printf("\n");
    }

    return 0;
}

Exercise 14
#include <stdio.h>
int main() {
    int c;
    int chars[128] = {0};

    while ((c = getchar()) != '\n') {
        ++chars[c];
    }

    printf("\nCharacter Frequency Histogram:\n");

    for (int i = 0; i < 128; i++) {
        if (chars[i] > 0) {
            printf("%c : ", i);

            for (int j = 0; j < chars[i]; j++)
                printf("*");

            printf("\n");
        }
    }
    return 0;
}

1 - 17 ~ 19


exercise 17
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

// EX 1-18




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


// EX 1-19

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


1-20 ~ 24
// Exercises
// EX 1-20

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



// EX 1-21

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

// EX 1-23

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



// EX 1-24

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


*/