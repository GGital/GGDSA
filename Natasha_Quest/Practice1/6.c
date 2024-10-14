#include<stdio.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    int cnt[n];
    int num[n];
    int sz = 0;
    for(int i = 0; i < n; i++) scanf("%d" , &arr[i]);
    for(int i = 0; i < n; i++) {
        int index = 0;
        while(index < sz && num[index] != arr[i]) index++;
        if(index >= sz) {
            num[index] = arr[i];
            cnt[index] = 1;
            sz++;
        }
        else {
            cnt[index]++;
        }
    }
    for(int i = 0; i < sz; i++) printf("%d %d\n" , num[i] , cnt[i]);
}
