// exercise 1 - 11&12
// program is for 11 and 12.
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