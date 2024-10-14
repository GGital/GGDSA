#include<string.h>
#include<stdio.h>

void reverse (char str[] , char res[] , int n , int remaining) {
    //printf("%s\n" , res);
    if(remaining == 0) {
        res[n] = '\0';
        return ;
    }
    else {
        res[remaining - 1] = str[n - remaining];
    }
    reverse(str , res , n , remaining - 1);
}
int main() {
    char str[50]; scanf("%s" , str);
    char res[50];
    //printf("%d" , strlen(str));
    reverse(str , res , strlen(str) , strlen(str));
    printf("%s" , res);
    return 0;
}
