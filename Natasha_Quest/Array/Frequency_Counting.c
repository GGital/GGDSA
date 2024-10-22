#include<stdio.h>

int main() {
    int n; scanf("%d" , &n);
    int freq[11] = {0};
    for(int i = 0; i < n; i++) {
        int x; scanf("%d" , &x);
        freq[x]++;
    }
    printf("%s%17s\n" , "Rating" , "Frequency");

    for(int i = 0; i < 11; i++) {
        printf("%6d%17d\n" , i , freq[i]);
    }
    return 0;
}
