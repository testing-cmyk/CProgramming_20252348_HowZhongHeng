//Exercise 5 - 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVAL 100

/* Stack variables */
int sp = 0;
double val[MAXVAL];

/* Push a value onto the stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Error: stack full\n");
}

/* Pop and return the top value */
double pop(void)
{
    if (sp > 0)
        return val[--sp];

    printf("Error: stack empty\n");
    return 0.0;
}

/* Evaluate reverse Polish expression */
int main(int argc, char *argv[])
{
    int i;
    double op2;

    /* Check for command-line arguments */
    if (argc < 2)
    {
        printf("Usage: expr operand operator operand ...\n");
        return 1;
    }

    /* Process each command-line argument */
    for (i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "+") == 0)
        {
            push(pop() + pop());
        }
        else if (strcmp(argv[i], "-") == 0)
        {
            op2 = pop();
            push(pop() - op2);
        }
        else if (strcmp(argv[i], "*") == 0)
        {
            push(pop() * pop());
        }
        else if (strcmp(argv[i], "/") == 0)
        {
            op2 = pop();

            if (op2 != 0.0)
                push(pop() / op2);
            else
            {
                printf("Error: division by zero\n");
                return 1;
            }
        }
        else
        {
            /* Convert argument into a number */
            char *end;
            double number = strtod(argv[i], &end);

            if (*argv[i] == '\0' || *end != '\0')
            {
                printf("Error: invalid argument '%s'\n", argv[i]);
                return 1;
            }

            push(number);
        }
    }

    /* Display final result */
    if (sp == 1)
        printf("Result: %.8g\n", pop());
    else
        printf("Error: invalid expression\n");

    return 0;
}
