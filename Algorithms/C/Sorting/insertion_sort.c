#include<stdio.h>

void insertion_sort(int arr[] , int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(arr[j] > key && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {2 , 5 , 6 ,3 , 1 , 8};
    insertion_sort(arr , (sizeof(arr) / sizeof(arr[0])));
    for(int i = 0; i < 6; i++) printf("%d " , arr[i]);
    return 0;
}
