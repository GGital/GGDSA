#include<stdio.h>

int main() {
    char s[150];
    scanf("%s" , s);
    int cnt = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
    }
    printf("%s" ,s);
    return 0;
}
