#include <stdio.h>
// Function Declarations
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);

int main()
{
    int choice;
    char again;
    float num1, num2, result;

    do
    {
        printf("\n=====================================\n");
        printf("      BASIC CALCULATOR PROGRAM\n");
        printf("=====================================\n");

        printf("Enter First Number: ");
        scanf("%f", &num1);

        printf("Enter Second Number: ");
        scanf("%f", &num2);

        printf("\nSelect Operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");

        printf("Enter Your Choice (1-4): ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                result = add(num1, num2);
                printf("\nResult = %.2f\n", result);
                break;

            case 2:
                result = subtract(num1, num2);
                printf("\nResult = %.2f\n", result);
                break;

            case 3:
                result = multiply(num1, num2);
                printf("\nResult = %.2f\n", result);
                break;

            case 4:
                if (num2 != 0)
                {
                    result = divide(num1, num2);
                    printf("\nResult = %.2f\n", result);
                }
                else
                {
                    printf("\nError! Division by zero is not allowed.\n");
                }
                break;

            default:
                printf("\nInvalid Choice! Please enter a valid option.\n");
        }

        printf("\nDo you want to perform another calculation? (Y/N): ");
        scanf(" %c", &again);

    } while (again == 'Y' || again == 'y');

    printf("\nThank you for using the Calculator!\n");

    return 0;
}

// Function Definitions

float add(float a, float b)
{
    return a + b;
}

float subtract(float a, float b)
{
    return a - b;
}

float multiply(float a, float b)
{
    return a * b;
}

float divide(float a, float b)
{
    return a / b;
}