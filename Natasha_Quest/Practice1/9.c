#include<stdio.h>

int main() {
    char s[150];
    scanf("%s" , s);
    int cnt = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ) cnt++;
    }
    printf("%d" ,cnt);
    return 0;
}
