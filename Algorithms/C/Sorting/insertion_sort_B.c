#include<stdio.h>

void insertion_sort(int arr[] , int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = 0;
        while(arr[i - j - 1] > key && i - j - 1 >= 0) {
            j++;
        }
        for(int k = 0; k < j; k++) arr[i-k] = arr[i-k-1];
        arr[i - j] = key;
    }
}

int main() {
    int arr[] = {2 , 5 , 6 ,3 , 1 , 8};
    //int arr[] = {5 , 2};
    insertion_sort(arr , (sizeof(arr) / sizeof(arr[0])));
    for(int i = 0; i < 6; i++) printf("%d " , arr[i]);
    return 0;
}
