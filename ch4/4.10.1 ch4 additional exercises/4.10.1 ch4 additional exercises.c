// exercise 4 - 3~9
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <errno.h>

#define MAXOP 100
#define MAXVAL 100
#define MAXBUF 100
#define MAXTOKEN 100

#define NUMBER '0'
#define NAME 'n'

/* Calculator stack */
double val[MAXVAL];
int sp = 0;

/* Variables a-z */
double variables[26] = { 0 };

/* Most recently printed value */
double last_printed = 0.0;

/* Input pushback buffer */
int buf[MAXBUF];
int bufp = 0;

/* Function prototypes */
int getop(char s[]);
int getch(void);
void ungetch(int c);
void ungets(const char s[]);

void push(double f);
double pop(void);
void print_top(void);
void duplicate(void);
void swap_top(void);
void clear_stack(void);

void execute_function(const char s[]);

/* Push a value onto the stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Error: stack full\n");
}

/* Pop the top value */
double pop(void)
{
    if (sp > 0)
        return val[--sp];

    printf("Error: stack empty\n");
    return 0.0;
}

/* Exercise 4-4: Print without popping */
void print_top(void)
{
    if (sp > 0)
    {
        last_printed = val[sp - 1];
        printf("Top: %.8g\n", last_printed);
    }
    else
    {
        printf("Error: stack empty\n");
    }
}

/* Exercise 4-4: Duplicate the top element */
void duplicate(void)
{
    if (sp > 0)
        push(val[sp - 1]);
    else
        printf("Error: stack empty\n");
}

/* Exercise 4-4: Swap the top two elements */
void swap_top(void)
{
    double temp;

    if (sp >= 2)
    {
        temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    }
    else
    {
        printf("Error: need two stack elements\n");
    }
}

/* Exercise 4-4: Clear the stack */
void clear_stack(void)
{
    sp = 0;
}

// Exercise 4-8 and 4-9
int getch(void)
{
    if (bufp > 0)
        return buf[--bufp];

    return getchar();
}

/* Push a character back into the input buffer */
void ungetch(int c)
{
    if (bufp >= MAXBUF)
    {
        printf("Error: input buffer full\n");
        return;
    }

    buf[bufp++] = c;
}

// Exercise 4-7
void ungets(const char s[])
{
    int len = (int)strlen(s);

    while (len > 0)
        ungetch((unsigned char)s[--len]);
}

int getop(char s[])
{
    int i = 0;
    int c;

/* Skip spaces and tabs */
    while ((c = getch()) == ' ' || c == '\t')
        ;

    if (c == EOF || c == '\n')
    {
        s[0] = (char)c;
        s[1] = '\0';
        return c;
    }

    s[i++] = (char)c;

/* Read the rest of the token */
    while ((c = getch()) != EOF &&
           c != ' ' && c != '\t' && c != '\n')
    {
        if (i < MAXTOKEN - 1)
            s[i++] = (char)c;
    }

    if (c == '\n' || c == EOF)
        ungetch(c);

    s[i] = '\0';

/* Check whether token is a number */
    {
        char *end;
        errno = 0;

        strtod(s, &end);

        if (end != s && *end == '\0' && errno != ERANGE)
            return NUMBER;
    }

/* Check for variable assignment, e.g. a= */
    if (strlen(s) == 2 &&
        islower((unsigned char)s[0]) &&
        s[1] == '=')
    {
        return NAME;
    }

/* Single-character operators and commands */
    if (strlen(s) == 1)
        return (unsigned char)s[0];

    return NAME;
}

// Exercise 4-5
void execute_function(const char s[])
{
    double op2;
    double op1;

    if (strcmp(s, "sin") == 0)
    {
        push(sin(pop()));
    }
    else if (strcmp(s, "exp") == 0)
    {
        push(exp(pop()));
    }
    else if (strcmp(s, "pow") == 0)
    {
        op2 = pop();
        op1 = pop();

        push(pow(op1, op2));
    }
    else
    {
        printf("Error: unknown function %s\n", s);
    }
}

/* Main calculator */
int main(void)
{
    int type;
    int variable_index;
    double op2;
    char s[MAXTOKEN];

    printf("K&R Postfix Calculator\n");
    printf("----------------------\n");
    printf("Operators: + - * / %%\n");
    printf("Commands: p (print), d (duplicate), ");
    printf("s (swap), c (clear)\n");
    printf("Functions: sin exp pow\n");
    printf("Variables: a-z, assignment: a=\n");
    printf("Variable v contains the last printed value.\n");
    printf("Enter Ctrl+Z followed by Enter to exit.\n\n");

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(strtod(s, NULL));
                break;

/* Exercise 4-3: Addition */
            case '+':
                push(pop() + pop());
                break;

/* Exercise 4-3: Subtraction */
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;

/* Exercise 4-3: Multiplication */
            case '*':
                push(pop() * pop());
                break;

/* Exercise 4-3: Division */
            case '/':
                op2 = pop();

                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("Error: division by zero\n");

                break;

/* Exercise 4-3: Modulus */
            case '%':
                op2 = pop();

                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("Error: modulus by zero\n");

                break;

/* Exercise 4-4: Print top */
            case 'p':
                print_top();
                break;

/* Exercise 4-4: Duplicate */
            case 'd':
                duplicate();
                break;

/* Exercise 4-4: Swap */
            case 's':
                swap_top();
                break;

/* Exercise 4-4: Clear */
            case 'c':
                clear_stack();
                printf("Stack cleared\n");
                break;

/* Exercise 4-5: Mathematical functions */
            case NAME:

                if (strlen(s) == 2 && s[1] == '=')
                {
                    variable_index = s[0] - 'a';

                    if (sp > 0)
                        variables[variable_index] = pop();
                    else
                        printf("Error: stack empty\n");
                }
                else if (strcmp(s, "sin") == 0 ||
                         strcmp(s, "exp") == 0 ||
                         strcmp(s, "pow") == 0)
                {
                    execute_function(s);
                }
                else if (strlen(s) == 1 &&
                         s[0] >= 'a' && s[0] <= 'z')
                {
                    if (s[0] == 'v')
                        push(last_printed);
                    else
                        push(variables[s[0] - 'a']);
                }
                else
                {
                    printf("Error: unknown command %s\n", s);
                }

                break;

            /* Exercise 4-6: Print result */
            case '\n':
                if (sp > 0)
                {
                    last_printed = pop();
                    printf("Result: %.8g\n", last_printed);
                }
                break;

            default:
                printf("Error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
