#include<stdio.h>

int sumofdigit(int res , int remain) {
    if(remain == 0) return res;
    else return sumofdigit(res + remain % 10 , remain / 10);
}

int main() {
    int n; scanf("%d" , &n);
    printf("%d" , sumofdigit(0 , n));
    return 0;
}
