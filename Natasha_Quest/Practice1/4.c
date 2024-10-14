#include<stdio.h>

int main() {
    int n , x; scanf("%d %d", &n , &x);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d" , &arr[i]);
    int index = 0;
    for(index = 0; index < n; index++) {
        if(arr[index] == x) break;
    }
    if(index == n) printf("-1");
    else printf("%d" , index);
    return 0;
}
