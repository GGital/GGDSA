#include<stdio.h>
#include<string.h>

int main() {
    char string[] = "CPE-KMUTT";
    int array[5] = {1 , 2 , 3 , 4 , 5};
    char resstr[10];
    int result[5] = {0};

    int n =  sizeof(array) / sizeof(array[0]);

    //array[0] = 15;

    //Normal Copy
    for(int i = 5 - 1; i >= 0; i--) result[i] = array[i];

    for(int i = 0; i < n; i++) printf("%d " , result[i]);

    printf("\n");

    // Duplicate and reverse
    for(int i = 5 - 1; i >= 0; i--) result[i] = array[n - 1 - i];

    for(int i = 0; i < n; i++) printf("%d " , result[i]);

    printf("\n");

    // Reverse string

    printf("%s\n" , string);

    int m = strlen(string);

    for(int i = 0; i < m; i++) resstr[i] = string[m - 1 - i];

    printf("%s\n" , resstr);

    return 0;
}
