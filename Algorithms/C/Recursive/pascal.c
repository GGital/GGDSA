#include<stdio.h>

int pascal(int n , int r) {
    if(r == 0 || r == n) return 1;
    if(r == 1 || r == n-1) return n;
    return pascal(n-1 , r) + pascal(n -1 , r-1);
}

int main() {
    int n , r; scanf("%d %d" , &n , &r);
    printf("%d" , pascal(n , r));
    return 0;
}
