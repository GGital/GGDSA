#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, value, pos;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory for n integers
    int *array = (int *)malloc(n * sizeof(int));

    // Initialize the array
    for (int i = 0; i < n; i++)
    {
        array[i] = i + 1;
    }

    printf("Enter the value to be inserted: ");
    scanf("%d", &value);

    printf("Enter the position to be inserted: ");
    scanf("%d", &pos);

    array = (int *)realloc(array, (n + 1) * sizeof(int));

    array[n] = value;
    for (int i = n; i > pos; i--)
    {
        array[i] ^= array[i - 1];
        array[i - 1] ^= array[i];
        array[i] ^= array[i - 1];
    }

    // Print the array
    for (int i = 0; i < n + 1; i++)
    {
        printf("%d ", array[i]);
    }

    free(array);
}