//�Ըշ�������������㹡�÷���١���Ẻ���ӡѴ�١ ��������Ѿ����ҡѺ n

#include<stdio.h>
#include<limits.h>

int main() {
    int n; scanf("%d" , &n);
    long long int dice[n + 1];
    for(int i = 0; i <= n; i++) dice[i] = 0;
    dice[0] = 1;
    for(int i = 0; i <= n; i++) {
        for(int j = 1; j <= 6; j++) {
            if(i + j <= n) dice[i + j] += dice[i];
        }
    }
    printf("%lld" , dice[n]);
    return 0;
}
