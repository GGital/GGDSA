#include<stdio.h>


int main() {
    int n; scanf("%d" , &n);
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < n - i; j++) printf(" ");
        int coef = 1;
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) coef = 1;
            else coef = coef * (i - j + 1) / j;
            printf("%d " , coef);
        }
        printf("\n");
    }
    return 0;
}
