// ยกกำลังแบบ O(log n) int เท่านั้น

#include<stdio.h>

long long pow(long long a , long long b) {
    if(b == 1) return a;
    if(b == 0) return 1;
    else if(b % 2 == 0 ) return pow(a , b / 2) * pow(a , b / 2);
    else return pow(a , b / 2) * pow(a , b / 2) * a;
}

int main() {
    long long a , b; scanf("%lld %lld" , &a , &b);
    printf("%lld" , pow(a , b));
    return 0;
}
