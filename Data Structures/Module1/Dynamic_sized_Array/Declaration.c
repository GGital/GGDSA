#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory for n integers
    int *array = (int *)malloc(n * sizeof(int));

    // Initialize the array
    for (int i = 0; i < n; i++)
    {
        array[i] = i + 1;
    }

    // Print the array
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}