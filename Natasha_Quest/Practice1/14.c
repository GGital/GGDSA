#include<stdio.h>

int main() {
    char s[150];
    char c;
    scanf("%s " , s);
    scanf("%c" , &c);
    int cnt = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == c) cnt++;
    }
    printf("%d" ,cnt);
    return 0;
}
