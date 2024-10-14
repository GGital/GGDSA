#include<stdio.h>

int part(int arr[] , int l ,int r) {
    int x = arr[r] , i = l;
    for(int k = l; k < r; k++) {
        if(arr[k] < x) {
            int temp = arr[k];
            arr[k] = arr[i];
            arr[i] = temp;
            i++;
        }
    }
    int temp = arr[r];
    arr[r] = arr[i];
    arr[i] = temp;
    return i;
}

void quick_sort(int arr[] , int l , int r , int n) {
    if(r - l <= 0) return;
    int p = part(arr , l , r);
    quick_sort(arr , l , p-1 , n);
    quick_sort(arr , p + 1 , r , n);
}

int main() {
    int arr[] = {2 , 5 , 7 , 3 , 8 , 9 , 10 , 0 , 1};
    int sz = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n" , sz);
    quick_sort(arr , 0 , sz - 1, sz);
    for(int i = 0; i < sz; i++) printf("%d " , arr[i]);
    return 0;
}

// 2 , 5 , 7 , 3 , 8 , 9 , 10 , 0 , 1
// 0 , 1 , 7 , 3 , 8 , 9 , 10 , 2 , 5
// 0 , 1 , 3 , 2 , 5 , 9 , 10 , 7 , 8
// 0 , 1 , 2 , 3 , 5 , 9 , 10 , 7 , 8
// 0 , 1 , 2 , 3 , 5 , 7 , 8 , 9 , 10
