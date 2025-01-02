#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, new_n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *array = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        array[i] = i + 1;
    }

    printf("Enter the new size of the array: ");
    scanf("%d", &new_n);

    array = (int *)realloc(array, new_n * sizeof(int));

    // Initialize new elements if array size increased
    if (new_n > n)
    {
        for (int i = n; i < new_n; i++)
        {
            array[i] = i + 1;
        }
    }

    // Print the resized array
    printf("Resized array elements: ");
    for (int i = 0; i < new_n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
}