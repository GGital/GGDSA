#include <stdio.h>

int sumofdigit(int remain)
{
    if (remain == 0)
        return 0;
    else
        return remain % 10 + sumofdigit(remain / 10);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", sumofdigit(n));
    return 0;
}
