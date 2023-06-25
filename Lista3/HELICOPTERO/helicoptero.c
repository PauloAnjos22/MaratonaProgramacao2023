#include <stdio.h>
#include <string.h>

// Retorna se o fugitivo conseguiu ou não fugir
char escape(int H, int P, int F, int D);

int main()
{
    int H, P, F, D;
    scanf("%d%d%d%d", &H, &P, &F, &D);

    printf("%c\n", escape(H, P, F, D));
    return 0;
}

char escape(int H, int P, int F, int D)
{
    while (F != H && F != P)
    {
        if (D == -1)
        {
            F--;
            if (F < 0)
            {
                F = 15;
            }
        }
        else
        {
            F++;
            if (F > 15)
            {
                F = 0;
            }
        }
    }
    if (F == H)
    {
        return 'S';
    }
    else
    {
        return 'N';
    }
}
