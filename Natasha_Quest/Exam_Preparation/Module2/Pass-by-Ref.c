#include<stdio.h>

void sum (int * a , int b) {
    *a += b;
}

int main() {
    int a = 10; int b = 5;
    printf("%d " , a);
    sum(&a , b);
    printf("%d " , a);
    return 0;
}
