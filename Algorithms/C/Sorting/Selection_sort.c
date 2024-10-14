#include<stdio.h>

void insertion_sort(int arr[] , int n) {
    for(int i = 0; i < n; i++) {
        int idx = i;
        for(int j = i; j < n; j++) {
            if(arr[j] < arr[idx]) idx = j;
        }
        int temp = arr[idx];
        arr[idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {2 , 5 , 7 , 3 , 8 , 9 , 10 , 0 , 1};
    int sz = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n" , sz);
    insertion_sort(arr , sz);
    for(int i = 0; i < sz; i++) printf("%d " , arr[i]);
    return 0;
}
