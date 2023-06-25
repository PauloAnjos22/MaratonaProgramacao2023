#include <stdio.h>
#include <string.h>

// Retorna se a melancia pode ser divida com peso par para ambas as partes
char *divisao(int peso);

int main()
{
    int peso;

    scanf("%d", &peso);

    printf("%s\n", divisao(peso));

    return 0;
}

char *divisao(int peso)
{
    if (peso != 2 && peso % 2 == 0)
    {
        return strdup("YES");
    }
    else
    {
        return strdup("NO");
    }
}