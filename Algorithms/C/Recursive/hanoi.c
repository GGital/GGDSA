// วืธีการเล่น hanoi แบบ step-by-step

#include<stdio.h>

void Hanoi(int idx , int a , int b , int c) {
    if(idx == 1) {
        printf("%d %d\n" , a , b);
        return;
    }
    Hanoi(idx-1 , a , c , b);
    printf("%d %d\n" , a , b);
    Hanoi(idx-1 , c , b , a);
}

int main() {
    int n; scanf("%d" , &n);
    Hanoi(n , 1 , 3 , 2);
    return 0;
}
