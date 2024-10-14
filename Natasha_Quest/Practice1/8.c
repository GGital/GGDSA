#include<stdio.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    int res[n];
    int sz = 0;
    for(int i = 0; i < n; i++) scanf("%d" , &arr[i]);
    for(int i = 0; i < n; i++) {
        int chk = 1;
        for(int j = 0; j < sz; j++) {
            if(res[j] == arr[i]) {
                chk = 0;
                break;
            }
        }
        if(chk) {
            res[sz++] = arr[i];
        }
    }
    for(int i = 0; i < sz; i++) printf("%d " , res[i]);
    return 0;
}
