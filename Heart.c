// Put in positive odd integer ONLY!
#include <stdio.h>
#include <stdlib.h>
#define _USE_MINGW_ANSI_STDIO 0

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int Q;
        scanf("%d", &Q);
        for (int j = 0; j < (Q / 2) + (Q / 4) + 1; j++)
        {
            for (int k = 0; k < Q; k++)
            {
                if (j < Q / 4)
                {
                    if (Q % 4 < 2)
                    {
                        if (k >= (Q / 2) - (Q / 4) - j && k <= (Q / 2) - (Q / 4) + j)
                            printf("#");
                        else if (k >= (Q / 2) + (Q / 4) - j && k <= (Q / 2) + (Q / 4) + j)
                            printf("#");
                        else
                            printf(".");
                    }
                    else if (Q % 4 > 2)
                    {
                        if (k >= (Q / 2) - (Q / 4) - j - 1 && k <= (Q / 2) - (Q / 4) + j)
                            printf("#");
                        else if (k >= (Q / 2) + (Q / 4) - j && k <= (Q / 2) + (Q / 4) + j + 1)
                            printf("#");
                        else
                            printf(".");
                    }
                }
                else if (j == Q / 4)
                {
                    printf("#");
                }
                else if (j > Q / 4)
                {
                    if (k >= j - Q / 4 && k < Q - (j - Q / 4))
                    {
                        printf("#");
                    }
                    else
                        printf(".");
                }
            }
            printf("\n");
        }
    }
    return 0;
}