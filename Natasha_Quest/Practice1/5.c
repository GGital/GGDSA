#include<stdio.h>

int part(int st , int en , int arr[]) {
    int pivot = arr[en];
    int j = st;
    for(int i = st; i < en; i++) {
        if(pivot > arr[i]) {
            if(i != j) {
                arr[i] ^= arr[j];
                arr[j] ^= arr[i];
                arr[i] ^= arr[j];
            }
            j++;
        }
    }
    //printf("%d %d %d\n", pivot , en , j);
    if(en != j) {
     arr[en] ^= arr[j];
     arr[j] ^= arr[en];
     arr[en] ^= arr[j];
    }
    return j;
}

void qsort(int st , int en , int arr[]) {
    int sz = en - st + 1;
    if(sz <= 1) return;
    //printf("%d %d %d %d\n" , st , en , sz , arr[en]);
    int p = part(st , en , arr);
    qsort(st , p - 1 , arr);
    qsort(p + 1, en , arr);
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d" , &arr[i]);
    qsort(0 , n-1 , arr);
    for(int i = 0; i < n; i++) printf("%d " , arr[i]);
    return 0;
}
