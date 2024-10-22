#include<stdio.h>

int main() {

    int n; scanf("%d" , &n);
    int data[n];
    for(int i = 0; i < n; i++) scanf("%d" , &data[i]);

    printf("%s%13s%17s\n" , "Element" , "Value" , "Histogram");

    for(int i = 0; i < n; i++) {
        printf("%7d%13d        " , i , data[i]);
        for(int j = 1; j <= data[i]; j++) printf("*");
        printf("\n");
    }

    return 0;
}
