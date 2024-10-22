#include<stdio.h>

int main() {
    int n; scanf("%d" , &n);
    for(int i = 1; i <= n; i++) {
        int sum = i * (i - 1) / 2;
        for(int j = 1; j <= i; j++) printf("%d " , sum + j);
        printf("\n");
    }
    return 0;
}
