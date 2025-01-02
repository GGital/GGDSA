#include <stdio.h>
#include <string.h>

int Palindrome(char s[], int i)
{
    int h = strlen(s);
    // printf("%d", h / 2);
    if (h / 2 > i)
    {
        if (s[i] == s[h - i - 1])
            return Palindrome(s, i + 1);
        else
            return 0;
    }
    else
        return 1;
}

int main()
{
    char s[100];
    scanf("%s", s);
    // printf("%s", s);
    printf("%d", Palindrome(s, 0));
}