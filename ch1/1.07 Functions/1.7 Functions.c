// exercise 1 - 7 & 15
#include <stdio.h>

/* Function declarations */
void displayMessage(void);
int addNumbers(int a, int b);
int squareNumber(int n);
int isEven(int n);

/* Main function */
int main(void)
{
    int num1, num2;
    int result;
    
    printf("-------------------------\n\n");

    /* Call a function without arguments */
    displayMessage();

    /* Get two numbers */
    printf("\nEnter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    /* Call addition function */
    result = addNumbers(num1, num2);

    printf("\nSum: %d\n", result);

    /* Call square function */
    printf("Square of first number: %d\n",
           squareNumber(num1));

    /* Check whether first number is even or odd */
    if (isEven(num1))
        printf("%d is even.\n", num1);
    else
        printf("%d is odd.\n", num1);

    return 0;
}

/* Display a message */
void displayMessage(void)
{
    printf("C function program.\n");
}

/* Add two integers */
int addNumbers(int a, int b)
{
    return a + b;
}

/* Calculate the square of a number */
int squareNumber(int n)
{
    return n * n;
}

/* Check whether a number is even */
int isEven(int n)
{
    return n % 2 == 0;
}

//  exercise 1 - 15
#include <stdio.h>

/* Function declaration */
float fahrToCelsius(float fahr);

/* Main function */
int main(void)
{
    float fahr;
    float celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Fahrenheit to Celsius Conversion\n");
    printf("--------------------------------\n\n");

    printf("Fahrenheit\tCelsius\n");

    fahr = lower;

    while (fahr <= upper)
    {
        celsius = fahrToCelsius(fahr);

        printf("%10.0f\t%7.1f\n", fahr, celsius);

        fahr = fahr + step;
    }

    return 0;
}

/* Convert Fahrenheit to Celsius */
float fahrToCelsius(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}