//หาจำนวนเหรียญที่ใช้ในการทอนให้น้อยที่สุดโดยให้ จำนวนเงิน และประเภทของเหรียญที่มี โดย input ต้องมีเหรียญ 1 เสมอ

#include<stdio.h>
#include<limits.h>

int main() {
    int n , k; scanf("%d %d" , &n , &k);
    int arr[n];
    long long int dp[k + 1];
    dp[0] = 0;
    for(int i = 1; i <= k; i++) dp[i] = INT_MAX;
    for(int i = 0; i < n; i++)  {
        scanf("%d" , &arr[i]);
    }
    for(int i = 0; i <= k; i++) {
        for(int j = 0; j < n; j++) {
            if(i + arr[j] <= k) {
                if(dp[i + arr[j]] > dp[i] + 1) dp[i + arr[j]] = dp[i] + 1;
            }
        }
    }
    printf("%lld" , dp[k]);
    return 0;
}
