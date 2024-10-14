#include<stdio.h>

int main() {
    int a = 3;
    int b = 7;
    printf("%d %d\n" , a , b);
    a ^= b;
    b ^= a;
    a ^= b;
    printf("%d %d" , a , b);
    return 0;
}
