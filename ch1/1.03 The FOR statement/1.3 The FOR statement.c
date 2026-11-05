//ex 1 - 5
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