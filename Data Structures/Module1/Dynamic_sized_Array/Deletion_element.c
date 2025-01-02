#include<stdio.h>
#include<stdlib.h>

int main() {
    int n , pos;
    scanf("%d", &n);

    int* array = (int*)malloc(n * sizeof(int));

    // Initialize the array
    for (int i = 0; i < n; i++)
    {
        array[i] = i + 1;
    }

    printf("Enter the position to be deleted: ");
    scanf("%d", &pos);

    for(int i = pos; i < n-1; i++) { 
        array[i] ^= array[i+1];
        array[i + 1] ^= array[i];
        array[i] ^= array[i+1];
    }

    n--;
    array = (int*)realloc(array , n * sizeof(int));


    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}