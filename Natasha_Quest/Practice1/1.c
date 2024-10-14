#include<stdio.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d" , &arr[i]);
    int mx = arr[0];
    for(int i = 1; i < n; i++) {
        mx = (arr[i] > mx) ? arr[i] : mx;
    }
    printf("%d" , mx);
    return 0;
}
