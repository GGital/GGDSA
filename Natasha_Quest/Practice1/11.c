#include<stdio.h>
#include<string.h>

int main() {
    char s[150];
    scanf("%s" , s);
    int st = 0;
    int en = strlen(s) - 1;
    while(st < en) {
        if(s[st++] != s[en--]) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}

// skibidi
// aabaa
