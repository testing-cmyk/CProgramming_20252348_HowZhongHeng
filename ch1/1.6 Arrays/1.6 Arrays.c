//ex 1 - 13~14
//exercise 13
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

// Exercise 14
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