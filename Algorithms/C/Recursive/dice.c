//วิธีทั้งหมดที่เป็นไปได้ในการทอยลูกเต๋าแบบไม่จำกัดลูก แล้วได้ผมลัพธ์เท่ากับ n

#include<stdio.h>
#include<limits.h>

long long dice (int remaining) {
    if(remaining < 0) return 0;
    if(remaining == 0) return 1;
    long long sum = 0;
    for(int i = 1; i <= 6; i++) {
        sum += dice(remaining - i);
    }
    return sum;
}

int main() {
    int n; scanf("%d" , &n);
    if(n == 0) printf("0");
    else printf("%d" , dice(n));
    return 0;
}
