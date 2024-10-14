#include<string.h>
#include<stdio.h>

int palin(int st , int en , char str[]) {
    if(st >= en) return 1;
    if(str[st] == str[en]) return palin(st + 1 , en - 1 , str);
    return 0;
}

int main() {
    char str[50]; scanf("%s" , str);
    printf("%d" , palin(0 , strlen(str) - 1 , str));
    return 0;
}
