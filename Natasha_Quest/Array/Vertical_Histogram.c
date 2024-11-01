#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int data[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &data[i]);
    int mx = data[0];
    for (int i = 0; i < n; i++)
        mx = (mx < data[i]) ? data[i] : mx;
    for (int i = mx; i > 0; i--)
    {
        for (int j = 0; j < n; j++)
            if (data[j] >= i)
                printf("*  ");
            else
                printf("   ");
        printf("\n");
    }
    return 0;
}