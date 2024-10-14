#include<stdio.h>
#include<string.h>

int main() {
    char s[150];
    scanf("%s" , s);
    int st = 0;
    int en = strlen(s) - 1;
    while(st < en) {
        s[st] ^= s[en];
        s[en] ^= s[st];
        s[st] ^= s[en];
        st++;
        en--;
    }
    printf("%s" , s);
    return 0;
}
