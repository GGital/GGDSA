#include<stdio.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d" , &arr[i]);
    int st = 0;
    int en = n - 1;
    while(st < en) {
        arr[st] ^= arr[en];
        arr[en] ^= arr[st];
        arr[st] ^= arr[en];
        st++;
        en--;
    }
    for(int i = 0; i < n; i++) printf("%d " , arr[i]);
    return 0;
}
