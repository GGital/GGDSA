#include<stdio.h>

int gcd(int a , int b) {
    if(b == 0) return a;
    return gcd(b , a % b);
}

int main() {
    int a , b; scanf("%d %d" , &a , &b);
    if(b > a) {
        b ^= a;
        a ^= b;
        b ^= a;
    }
    printf("%d" , a * b / gcd(a , b)); // a * b = gcd(a , b) * lcm(a , b)
    return 0;
}
