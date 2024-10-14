//หาจำนวนเหรียญที่ใช้ในการทอนให้น้อยที่สุดโดยให้ จำนวนเงิน และประเภทของเหรียญที่มี โดย input ต้องมีเหรียญ 1 เสมอ

#include<stdio.h>
#include<limits.h>

long long coin (int arr[] , int remaining , int n) {
    if(remaining == 0) return 0;
    if(remaining < 0) return INT_MAX;
    long long best = INT_MAX;
    for(int i = 0; i < n; i++) {
        long long res = coin(arr , remaining - arr[i] , n) + 1;
        if(best > res) best = res;
    }
    return best;
}

int main() {
    int n , k; scanf("%d %d" , &n , &k);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d" , &arr[i]);
    printf("%d" , coin(arr , k , n));
    return 0;
}
