// exercise 4 - 3
#include <stdio.h>
#include <stdlib.h>
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

/* Function prototypes */
int getop(char s[]);
void push(double f);
double pop(void);

/* Main postfix calculator */
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    printf("Postfix Calculator\n");
    printf("Enter expressions in postfix notation.\n");
    printf("Use Ctrl+Z followed by Enter to exit on Windows.\n\n");

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s));
                break;

            case '+':
                push(pop() + pop());
                break;

            case '*':
                push(pop() * pop());
                break;

            case '-':
                op2 = pop();
                push(pop() - op2);
                break;

            case '/':
                op2 = pop();

                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("Error: division by zero\n");

                break;

            case '\n':
                if (sp > 0)
                    printf("Result: %.8g\n", pop());
                break;

            default:
                printf("Error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

/* Push a value onto the stack */
void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("Error: stack full\n");
    }
}

/* Pop and return the top value */
double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }

    printf("Error: stack empty\n");
    return 0.0;
}

/* Get the next operator or numeric operand */
int getop(char s[])
{
    int i = 0;
    int c;

    /* Skip whitespace except newline */
    while ((s[0] = c = getchar()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (c == EOF || c == '\n')
        return c;

    /* Determine whether input is a number */
    if (!isdigit(c) && c != '.' && c != '-')
        return c;

    /* Handle negative numbers */
    if (c == '-')
    {
        int next = getchar();

        if (!isdigit(next) && next != '.')
        {
            if (next != EOF)
                ungetc(next, stdin);

            return '-';
        }
        s[++i] = (char)next;
    }
    /* Read remaining digits */
    if (isdigit(c) || (c == '-' && isdigit(s[1])))
    {
        while (isdigit(s[i + 1] = c = getchar()))
            i++;

        if (c == '.')
        {
            while (isdigit(s[++i] = c = getchar()))
                ;
        }
    }
    s[i + 1] = '\0';

    if (c != EOF)
        ungetc(c, stdin);
    return NUMBER;
}