#include<stdio.h>

int main() {
    int n , m; scanf("%d %d", &n , &m);
    int arr1[n];
    int arr2[m];
    int res[n + m];
    for(int i = 0; i < n; i++) scanf("%d" , &arr1[i]);
    for(int i = 0; i < m; i++) scanf("%d" , &arr2[i]);
    int index = 0;
    for(int i = 0; i < n; i++) res[index++] = arr1[i];
    for(int i = 0; i < m; i++) res[index++] = arr2[i];
    for(int i = 0; i < index; i++) printf("%d " , res[i]);
    return 0;
}
