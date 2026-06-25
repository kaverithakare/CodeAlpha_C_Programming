#include <stdio.h>

void inputMatrix(int rows, int cols, int matrix[10][10]);
void displayMatrix(int rows, int cols, int matrix[10][10]);
void addMatrix(int rows, int cols, int A[10][10], int B[10][10]);
void multiplyMatrix(int rows, int cols, int A[10][10], int B[10][10]);
void transposeMatrix(int rows, int cols, int matrix[10][10]);

int main()
{
    int A[10][10], B[10][10];
    int rows, cols, choice;
    char again;

    do
    {
        printf("\n===== MATRIX OPERATIONS =====\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Transpose of Matrix A\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter number of rows: ");
                scanf("%d", &rows);

                printf("Enter number of columns: ");
                scanf("%d", &cols);

                printf("\nEnter elements of Matrix A:\n");
                inputMatrix(rows, cols, A);

                printf("\nEnter elements of Matrix B:\n");
                inputMatrix(rows, cols, B);

                addMatrix(rows, cols, A, B);
                break;

            case 2:
                printf("Enter number of rows: ");
                scanf("%d", &rows);

                printf("Enter number of columns: ");
                scanf("%d", &cols);

                printf("\nEnter elements of Matrix A:\n");
                inputMatrix(rows, cols, A);

                printf("\nEnter elements of Matrix B:\n");
                inputMatrix(rows, cols, B);

                multiplyMatrix(rows, cols, A, B);
                break;

            case 3:
                printf("Enter number of rows: ");
                scanf("%d", &rows);

                printf("Enter number of columns: ");
                scanf("%d", &cols);

                printf("\nEnter elements of Matrix A:\n");
                inputMatrix(rows, cols, A);

                transposeMatrix(rows, cols, A);
                break;

            default:
                printf("Invalid Choice!\n");
        }

        printf("\nDo you want to perform another operation? (Y/N): ");
        scanf(" %c", &again);

    } while(again == 'Y' || again == 'y');

    printf("\nThank You!\n");

    return 0;
}

void inputMatrix(int rows, int cols, int matrix[10][10])
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int rows, int cols, int matrix[10][10])
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int rows, int cols, int A[10][10], int B[10][10])
{
    int result[10][10];
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nMatrix Addition Result:\n");
    displayMatrix(rows, cols, result);
}

void multiplyMatrix(int rows, int cols, int A[10][10], int B[10][10])
{
    int result[10][10];
    int i, j, k;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            result[i][j] = 0;

            for(k = 0; k < cols; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nMatrix Multiplication Result:\n");
    displayMatrix(rows, cols, result);
}

void transposeMatrix(int rows, int cols, int matrix[10][10])
{
    int transpose[10][10];
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("\nTranspose of Matrix A:\n");

    for(i = 0; i < cols; i++)
    {
        for(j = 0; j < rows; j++)
        {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }
}