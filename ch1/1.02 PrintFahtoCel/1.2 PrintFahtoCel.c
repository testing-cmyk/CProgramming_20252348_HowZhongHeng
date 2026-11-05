//ex 1 - 3~4
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