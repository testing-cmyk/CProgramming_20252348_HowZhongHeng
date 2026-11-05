// Exercises 5 - 3~4
// Exercises 5 - 3
#include <stdio.h>

/* Concatenate t to the end of s using pointers */
void my_strcat(char *s, char *t)
{
    /* Find the end of string s */
    while (*s != '\0')
        s++;

    /* Copy string t to the end of s */
    while ((*s++ = *t++) != '\0')
        ;
}

int main(void)
{
    char s[100] = "Hello ";
    char t[] = "World";

    printf("Before concatenation:\n");
    printf("String s: %s\n", s);
    printf("String t: %s\n", t);

    my_strcat(s, t);

    printf("\nAfter concatenation:\n");
    printf("String s: %s\n", s);

    return 0;
}

// Exercises 5 - 4

#include <stdio.h>
#include <string.h>

/* Check whether t occurs at the end of s */
int strend(char *s, char *t)
{
    char *end_s;
    char *end_t;

    /* Find the end of string s */
    end_s = s;
    while (*end_s != '\0')
        end_s++;

    /* Find the end of string t */
    end_t = t;
    while (*end_t != '\0')
        end_t++;

    /* Compare string lengths */
    if (end_t - t > end_s - s)
        return 0;

    /* Move pointers to the beginning of the suffix */
    end_s -= end_t - t;

    /* Compare both strings */
    while (*end_s != '\0' && *end_s == *t)
    {
        end_s++;
        t++;
    }

    return (*end_s == '\0' && *t == '\0');
}

int main(void)
{
    char s[] = "Hello World";

    printf("String: %s\n\n", s);

    printf("strend(s, \"World\"): %d\n",
           strend(s, "World"));

    printf("strend(s, \"Hello\"): %d\n",
           strend(s, "Hello"));

    printf("strend(s, \"lo World\"): %d\n",
           strend(s, "lo World"));

    printf("strend(s, \"Computer\"): %d\n",
           strend(s, "Computer"));

    return 0;
}
