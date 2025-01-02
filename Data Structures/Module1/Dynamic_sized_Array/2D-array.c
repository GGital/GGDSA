#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows = 3, cols = 4;

    // Allocate memory for an array of pointers
    int **array = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        array[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize and print the array
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            array[i][j] = i + j;
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < rows; i++)
    {
        free(array[i]);
    }
    free(array);

    return 0;
}