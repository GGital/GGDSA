#include<stdio.h>
#include<string.h>

int main() {
    char s[150] , ss[150] , res[150];
    scanf("%s" , s);
    scanf("%s" , ss);
    int index = 0;
    for(int i = 0; s[i] != '\0'; i++) res[index++] = s[i];
    for(int i = 0; ss[i] != '\0'; i++) res[index++] = ss[i];
    res[index] = '\0';
    printf("%s" , res);
    return 0;
}
